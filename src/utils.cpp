// Copyright (c) 2023 zozibush, All Rights Reserved.
// Authors: zozibush

#include "math/utils.hpp"

#include <cmath>
#include <stdexcept>

namespace zozibush::math {
auto Add(double lhs, double rhs) -> double {
  if (std::isnan(lhs) || std::isnan(rhs) || std::isinf(lhs) ||
      std::isinf(rhs)) {
    throw std::invalid_argument("lhs or rhs is nan or inf");
  }
  return lhs + rhs;
}
auto Subtract(double lhs, double rhs) -> double {
  if (std::isnan(lhs) || std::isnan(rhs) || std::isinf(lhs) ||
      std::isinf(rhs)) {
    throw std::invalid_argument("lhs or rhs is nan or inf");
  }
  return lhs - rhs;
}
}  // namespace zozibush::math
