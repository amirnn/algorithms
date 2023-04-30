#pragma once

namespace bluecpp {

void getInfo();

class Algorithm {
public:
  virtual void run() = 0;
};

} // namespace bluecpp
