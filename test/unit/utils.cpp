// Copyright (c) 2023 zozibush, All Rights Reserved.
// Authors: zozibush

#include "math/utils.hpp"

#include <cmath>
#include <limits>
#include <stdexcept>

#include "gtest/gtest.h"
namespace zozibush::math {
TEST(MathUtils, Add) {
  EXPECT_THROW(Add(0.0, std::nan("")), std::invalid_argument);
  EXPECT_THROW(Add(std::nan(""), 0.0), std::invalid_argument);
  EXPECT_THROW(Add(std::nan(""), std::nan("")), std::invalid_argument);
  EXPECT_THROW(Add(0.0, std::numeric_limits<double>::infinity()),
               std::invalid_argument);
  EXPECT_THROW(Add(std::numeric_limits<double>::infinity(), 0.0),
               std::invalid_argument);
  EXPECT_THROW(Add(std::numeric_limits<double>::infinity(),
                   std::numeric_limits<double>::infinity()),
               std::invalid_argument);

  EXPECT_EQ(Add(0.0, 0.0), 0.0);
  EXPECT_EQ(Add(1.0, 0.0), 1.0);
  EXPECT_EQ(Add(0.0, 1.0), 1.0);
  EXPECT_EQ(Add(0.0, 0.5), 0.5);
  EXPECT_EQ(Add(0.5, 0.0), 0.5);
  EXPECT_EQ(Add(0.5, 0.5), 1.0);
}

}  // namespace zozibush::math