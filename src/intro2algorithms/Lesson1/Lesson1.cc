#include "Libs/Student.hpp"
#include "Libs/Record.hpp"

#include <iostream>
#include <ranges>

using namespace bluecpp;

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