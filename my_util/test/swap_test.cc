// Copyright [2022] <Remo Dietlicher>
//

#include "../swap.h"
#include <gtest/gtest.h>

// Demonstrate some basic assertions.
TEST(MyUtilTest, TestIntegers) {
  int a = 5;
  int b = 8;

  my_util::swap(&a, &b);
  EXPECT_EQ(a, 8);
  EXPECT_EQ(b, 5);
}
