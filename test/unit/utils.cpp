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

TEST(MathUtils, Subtract) {
  EXPECT_THROW(Subtract(0.0, std::nan("")), std::invalid_argument);
  EXPECT_THROW(Subtract(std::nan(""), 0.0), std::invalid_argument);
  EXPECT_THROW(Subtract(std::nan(""), std::nan("")), std::invalid_argument);
  EXPECT_THROW(Subtract(0.0, std::numeric_limits<double>::infinity()),
               std::invalid_argument);
  EXPECT_THROW(Subtract(std::numeric_limits<double>::infinity(), 0.0),
               std::invalid_argument);
  EXPECT_THROW(Subtract(std::numeric_limits<double>::infinity(),
                        std::numeric_limits<double>::infinity()),
               std::invalid_argument);

  EXPECT_EQ(Subtract(0.0, 0.0), 0.0);
  EXPECT_EQ(Subtract(1.0, 0.0), 1.0);
  EXPECT_EQ(Subtract(0.0, 1.0), -1.0);
  EXPECT_EQ(Subtract(0.0, 0.5), -0.5);
  EXPECT_EQ(Subtract(0.5, 0.0), 0.5);
  EXPECT_EQ(Subtract(0.5, 0.5), 0.0);
  EXPECT_EQ(Subtract(-0.5, -0.5), 0.0);
  EXPECT_EQ(Subtract(-0.5, 0.5), -1.0);
}

TEST(MathUtils, Multiply) {
  EXPECT_THROW(Multiply(0.0, std::nan("")), std::invalid_argument);
  EXPECT_THROW(Multiply(std::nan(""), 0.0), std::invalid_argument);
  EXPECT_THROW(Multiply(std::nan(""), std::nan("")), std::invalid_argument);
  EXPECT_THROW(Multiply(0.0, std::numeric_limits<double>::infinity()),
               std::invalid_argument);
  EXPECT_THROW(Multiply(std::numeric_limits<double>::infinity(), 0.0),
               std::invalid_argument);
  EXPECT_THROW(Multiply(std::numeric_limits<double>::infinity(),
                        std::numeric_limits<double>::infinity()),
               std::invalid_argument);

  EXPECT_EQ(Multiply(0.0, 0.0), 0.0);
  EXPECT_EQ(Multiply(1.0, 0.0), 0.0);
  EXPECT_EQ(Multiply(0.0, 1.0), 0.0);
  EXPECT_EQ(Multiply(1.0, 1.0), 1.0);
  EXPECT_EQ(Multiply(1.2, 1.2), 1.44);
  EXPECT_EQ(Multiply(100.0, 0.5), 50.0);
  EXPECT_EQ(Multiply(4.2, 2.0), 8.4);
  EXPECT_EQ(Multiply(-5.0, -4.0), 20.0);
  EXPECT_EQ(Multiply(5.0, -4.0), -20.0);
  EXPECT_EQ(Multiply(-5.0, 4.0), -20.0);
  EXPECT_EQ(Multiply(5.0, 4.0), 20.0);
}

TEST(MathUtils, Divide) {
  EXPECT_THROW(Divide(0.0, std::nan("")), std::invalid_argument);
  EXPECT_THROW(Divide(std::nan(""), 0.0), std::invalid_argument);
  EXPECT_THROW(Divide(std::nan(""), std::nan("")), std::invalid_argument);
  EXPECT_THROW(Divide(0.0, std::numeric_limits<double>::infinity()),
               std::invalid_argument);
  EXPECT_THROW(Divide(std::numeric_limits<double>::infinity(), 0.0),
               std::invalid_argument);
  EXPECT_THROW(Divide(std::numeric_limits<double>::infinity(),
                      std::numeric_limits<double>::infinity()),
               std::invalid_argument);
  EXPECT_THROW(Divide(1.0, 0.0), std::invalid_argument);
  EXPECT_NO_THROW(Divide(0.0, 1.0));

  EXPECT_EQ(Divide(0.0, 1.0), 0.0);
  EXPECT_EQ(Divide(1.0, 1.0), 1.0);
  EXPECT_EQ(Divide(1.2, 1.2), 1.0);
  EXPECT_EQ(Divide(1.2, 1.0), 1.2);
  EXPECT_EQ(Divide(100.0, 5.0), 20.0);
  EXPECT_EQ(Divide(-100.0, 5.0), -20.0);
  EXPECT_EQ(Divide(100.0, -5.0), -20.0);
  EXPECT_EQ(Divide(-100.0, -5.0), 20.0);
}
}  // namespace zozibush::math
