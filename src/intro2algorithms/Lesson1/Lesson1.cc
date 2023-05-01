#include "boost/uuid/random_generator.hpp"
#include <__algorithm/ranges_for_each.h>
#include <__ranges/transform_view.h>
#include <algorithm>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <iostream>
#include <optional>
#include <ostream>
#include <ranges>
#include <stdlib.h>
#include <string>
#include <tuple>
#include <vector>

struct Date {
  int day{0};
  int month{0};
  int year{0};

  friend std::ostream &operator<<(std::ostream &o, Date const &date);
  bool operator==(Date const &rhs) const noexcept {
    return (this->day == rhs.day && this->month == rhs.month &&
            this->year == rhs.year);
  }
};

std::ostream &operator<<(std::ostream &o, Date const &date) {
  return (o << date.day << "." << date.month << "." << date.year);
}

class Student {
private:
  using uuid = boost::uuids::uuid;
  using rg = boost::uuids::random_generator;
  const uuid m_uuid;

public:
  Student(std::string &&name, Date &&date) noexcept
      : m_uuid(rg()()), name{name}, birthday{date} {};
  std::string name;
  Date birthday;
  uuid const &get_id() const { return this->m_uuid; }

  friend std::ostream &operator<<(std::ostream &o, Student const &student);
};

std::ostream &operator<<(std::ostream &o, Student const &student) {
  return (o << "Name: " << student.name
            << "Date of Birthday: " << student.birthday);
}

template <class T> class Record {
private:
  std::vector<T> m_records;

public:
  Record(std::vector<T> &&records) : m_records{records} {};
  Record(std::vector<T> &records) : m_records{records} {};

  [[nodiscard]] virtual auto find_matches() const
      -> std::optional<std::vector<T>>;

  virtual ~Record() = default;
};

template <>
auto Record<Student>::find_matches() const
    -> std::optional<std::vector<Student>> {
  std::vector<Student> matches{};
  matches.reserve(this->m_records.size());

  std::ranges::for_each(this->m_records, [&](Student const &item) {
    std::ranges::for_each(this->m_records, [&](Student const &otherItem) {
      if (item.get_id() != otherItem.get_id() &&
          item.birthday == otherItem.birthday) {
        matches.push_back(item);
        matches.push_back(otherItem);
      }
    });
  });
  if (!matches.empty()) {
    return std::move(matches);
  } else {
    return {};
  }
}

int main() {
  auto students = std::vector<Student>{{"Amir", {9, 4, 1992}},
                                       {"Shiva", {19, 07, 1994}},
                                       {"SomeOne", {9, 4, 1992}}};
  auto records = Record<Student>(students);
  const auto matches = records.find_matches();
  if (matches.has_value()) {
    std::ranges::for_each(matches.value(), [](auto const &item) {
      std::cout << item << std::endl;
    });
  } else {
    std::cout << "No Matches!" << std::endl;
  }
  return 1;
}