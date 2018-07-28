#include <gtest/gtest.h>

#include "filter.h"

// 1.29.168.152        222.173.235.246
// 222.173.235.246     222.130.177.64
// 1.1.234.8        -> 222.82.198.61
// 222.130.177.64      1.70.44.170
// 1.70.44.170         1.29.168.152
// 222.82.198.61       1.1.234.8
TEST(TestFilter, ReverseLexicographicallySort)
{
  const ip_pool_t before_sort = {{1, 29, 168, 152},
                                 {222, 173, 235, 246},
                                 {1, 1, 234, 8},
                                 {222, 130, 177, 64},
                                 {1, 70, 44, 170},
                                 {222, 82, 198, 61}};
  ip_pool_t after_sort{before_sort};

  reverse_lexicographically_sort(after_sort);

  ASSERT_EQ(after_sort.size(), before_sort.size());
  EXPECT_EQ(after_sort.at(0), before_sort.at(1));
  EXPECT_EQ(after_sort.at(1), before_sort.at(3));
  EXPECT_EQ(after_sort.at(2), before_sort.at(5));
  EXPECT_EQ(after_sort.at(3), before_sort.at(4));
  EXPECT_EQ(after_sort.at(4), before_sort.at(0));
  EXPECT_EQ(after_sort.at(5), before_sort.at(2));
}

TEST(TestFilter, FilterByFirstByte)
{
  const ip_pool_t ip_pool = {{1, 29, 168, 152},
                             {222, 173, 235, 246},
                             {1, 1, 234, 8},
                             {222, 130, 177, 64},
                             {1, 70, 44, 170},
                             {222, 82, 198, 61}};

  const ip_pool_t filtered = filter(ip_pool, 1);
  ASSERT_EQ(filtered.size(), 3);
  EXPECT_EQ(filtered.at(0), ip_pool.at(0));
  EXPECT_EQ(filtered.at(1), ip_pool.at(2));
  EXPECT_EQ(filtered.at(2), ip_pool.at(4));
}

TEST(TestFilter, FilterByFirstAndSecondByte)
{
  const ip_pool_t ip_pool = {{1, 29, 168, 152},
                             {222, 173, 235, 246},
                             {1, 1, 234, 8},
                             {222, 130, 177, 64},
                             {1, 70, 44, 170},
                             {222, 82, 198, 61}};

  const ip_pool_t filtered = filter(ip_pool, 1, 70);
  ASSERT_EQ(filtered.size(), 1);
  EXPECT_EQ(filtered.at(0), ip_pool.at(4));
}

TEST(TestFilter, FilterByAnyByte)
{
  const ip_pool_t ip_pool = {{1, 29, 168, 152},
                             {222, 173, 235, 246},
                             {29, 1, 234, 8},
                             {222, 130, 177, 64},
                             {1, 70, 44, 170},
                             {222, 82, 198, 29}};

  const ip_pool_t filtered = filter_any(ip_pool, 29);
  ASSERT_EQ(filtered.size(), 3);
  EXPECT_EQ(filtered.at(0), ip_pool.at(0));
  EXPECT_EQ(filtered.at(1), ip_pool.at(2));
  EXPECT_EQ(filtered.at(2), ip_pool.at(5));
}
