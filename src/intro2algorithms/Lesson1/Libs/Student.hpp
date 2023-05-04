//
// Created by Amir Nourinia on 04.05.23.
//
#pragma once

#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <boost/uuid/random_generator.hpp>

#include "Date.hpp"

namespace bluecpp {

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

} // bluecpp
