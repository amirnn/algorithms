//
// Created by Amir Nourinia on 04.05.23.
//
#pragma once

#include <ostream>

namespace bluecpp {

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

} // bluecpp

