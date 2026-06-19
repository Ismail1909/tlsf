#include"tlsf.h"

#include <gtest/gtest.h>

TEST(TlsfTest, BasicAllocTest) {
  int y = allocate();
  EXPECT_EQ(y, 1);
}
