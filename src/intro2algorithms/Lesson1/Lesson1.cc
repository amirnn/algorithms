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

  void operator<<(std::ostream &o) const {
    o << this->day << "." << this->month << "." << this->year;
  }
};

struct Student {
  std::string name;
  Date birthday;

  void operator<<(std::ostream &o) const {
    o << "Name: " << this->name << "Date of Birthday: " << this->birthday
      << std::endl;
  }
};

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
  this->m_records | std::ranges::views::filter([](auto const &item){
    
  }
                        std::filter this->m_records.filter this->m_records
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