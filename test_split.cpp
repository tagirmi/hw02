#include <gtest/gtest.h>

#include "split.h"

// ("",  '.') -> [""]
TEST(TestSplit, EmptyString)
{
    auto result = split("", '.');

    ASSERT_EQ(result.size(), 1);
    EXPECT_TRUE(result.at(0).empty());
}

// ("11", '.') -> ["11"]
TEST(TestSplit, NoDelimiters)
{
    auto result = split("11", '.');

    ASSERT_EQ(result.size(), 1);
    EXPECT_EQ(result.at(0), "11");
}

// ("..", '.') -> ["", "", ""]
TEST(TestSplit, OnlyDelimiters)
{
    auto result = split("..", '.');

    ASSERT_EQ(result.size(), 3);
    EXPECT_TRUE(result.at(0).empty());
    EXPECT_TRUE(result.at(1).empty());
    EXPECT_TRUE(result.at(2).empty());
}

// ("11.", '.') -> ["11", ""]
TEST(TestSplit, EndsWithDelimiter)
{
    auto result = split("11.", '.');

    ASSERT_EQ(result.size(), 2);
    EXPECT_EQ(result.at(0), "11");
    EXPECT_TRUE(result.at(1).empty());
}

// (".11", '.') -> ["", "11"]
TEST(TestSplit, BeginsWithDelimiter)
{
    auto result = split(".11", '.');

    ASSERT_EQ(result.size(), 2);
    EXPECT_TRUE(result.at(0).empty());
    EXPECT_EQ(result.at(1), "11");
}

// ("11.22", '.') -> ["11", "22"]
TEST(TestSplit, DelimiterInTheMiddle)
{
    auto result = split("11.22", '.');

    ASSERT_EQ(result.size(), 2);
    EXPECT_EQ(result.at(0), "11");
    EXPECT_EQ(result.at(1), "22");
}

