#include <algorithm>
#include <iostream>
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
};

std::ostream &operator<<(std::ostream &o, Date const &date) {
  return (o << date.day << "." << date.month << "." << date.year);
}

struct Student {
  std::string name;
  Date birthday;

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
  Record(std::vector<T> &&records);
  Record(std::vector<T> &records);

  virtual std::vector<T> find_matches() const;

  virtual ~Record() = default;
};

template <class T> std::vector<T> Record<T>::find_matches() const {
  return (this->m_records | std::views::);
}

int main() {
  auto students =
      std::vector<Student>{{"Amir", {9, 4, 1992}}, {"Shiva", {19, 07, 1994}}};
  auto records = Record<Student>(students);
  auto matches = records.find_matches();

  for (const auto &student : matches) {
    std::cout << student << std::endl;
  }
  return 1;
}