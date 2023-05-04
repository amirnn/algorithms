//
// Created by Amir Nourinia on 04.05.23.
//

#pragma once

#include <vector>
#include <optional>

namespace bluecpp {

template<class T> class Record {
private:
  std::vector<T> m_records;

public:
  Record(std::vector<T> &&records) : m_records{records} {};
  Record(std::vector<T> &records) : m_records{records} {};

  [[nodiscard]] virtual auto find_matches() const
  -> std::optional<std::vector<T>>;

  virtual ~Record() = default;
};

} // bluecpp

