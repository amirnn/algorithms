//
// Created by Amir Nourinia on 04.05.23.
//

#include "Date.hpp"

namespace bluecpp {

std::ostream &operator<<(std::ostream &o, Date const &date) {
  return (o << date.day << "." << date.month << "." << date.year);
}

} // bluecpp