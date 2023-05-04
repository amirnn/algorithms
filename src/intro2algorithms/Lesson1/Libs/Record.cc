//
// Created by Amir Nourinia on 04.05.23.
//

#include "Record.hpp"
#include "Student.hpp"

namespace bluecpp {
template<>
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
} // bluecpp