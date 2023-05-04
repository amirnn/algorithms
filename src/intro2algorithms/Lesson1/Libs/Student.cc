//
// Created by Amir Nourinia on 04.05.23.
//

#include "Student.hpp"

namespace bluecpp {
std::ostream &operator<<(std::ostream &o, Student const &student) {
  return (o << "ID: " << student.m_uuid << ", Name: " << student.name
			<< ", Date of Birthday: " << student.birthday);
}
} // bluecpp