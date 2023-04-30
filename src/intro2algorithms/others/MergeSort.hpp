#pragma once

#include <array>
#include <cstddef>
#include <string>

#include "Algorithms.hpp"

namespace bluecpp {

template <typename T, size_t N> class MergeSort : public Algorithm {
public:
  std::array<T, N> data;
  void run() override;
};

} // namespace bluecpp
