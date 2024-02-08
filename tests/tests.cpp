#include "longest_common_substring.h"
#include "calculate_trigrams_amount.h"
#include "gtest/gtest.h"
#include "utils.h"

TEST(CalculateTrigramsAmount, StringsWithCommonTrigrams1)
{
    const std::string str1{"computed"};
    const std::string str2{"composted"};
    LongestCommonSubstring lcs(str1, str2);
    EXPECT_EQ(calculateTrigramsAmount(lcs), 2);
}

TEST(CalculateTrigramsAmount, StringsWithMultiplyTrigrams)
{
    const std::string str1{"abacacabaabacac"};
    const std::string str2{"abaa"};
    LongestCommonSubstring lcs(str1, str2);
    EXPECT_EQ(calculateTrigramsAmount(lcs), 2);
}

TEST(CalculateTrigramsAmount, StringsWithCommonTrigrams2)
{
    const std::string str1{"computed"};
    const std::string str2{"smelly compost"};
    LongestCommonSubstring lcs(str1, str2);
    EXPECT_EQ(calculateTrigramsAmount(lcs), 2);
}

TEST(CalculateTrigramsAmount, StringsWithoutCommonTrigrams)
{
    const std::string str1{"abc"};
    const std::string str2{"def"};
    LongestCommonSubstring lcs(str1, str2);
    EXPECT_EQ(calculateTrigramsAmount(lcs), 0);
}

TEST(CalculateTrigramsAmount, SameStrings)
{
    const std::string str1{"computed"};
    const std::string str2{"computed"};
    LongestCommonSubstring lcs(str1, str2);
    EXPECT_EQ(calculateTrigramsAmount(lcs), 6);
}

TEST(CalculateTrigramsAmount, OneEmptyString)
{
    const std::string str1{""};
    const std::string str2{"computed"};
    LongestCommonSubstring lcs(str1, str2);
    EXPECT_EQ(calculateTrigramsAmount(lcs), 0);
}

TEST(CalculateTrigramsAmount, OneEmptyStringReversed)
{
    const std::string str1{"computed"};
    const std::string str2{""};
    LongestCommonSubstring lcs(str1, str2);
    EXPECT_EQ(calculateTrigramsAmount(lcs), 0);
}

TEST(CalculateTrigramsAmount, BothStringsEmpty)
{
    const std::string str1{""};
    const std::string str2{""};
    LongestCommonSubstring lcs(str1, str2);
    EXPECT_EQ(calculateTrigramsAmount(lcs), 0);
}

TEST(CalculateTrigramsAmount, SameStringsWithDifferentCases)
{
    const std::string str1{"AmbuLaNce"};
    const std::string str2{"ambulance"};
    LongestCommonSubstring lcs(str1, str2);
    EXPECT_EQ(calculateTrigramsAmount(lcs), 7);
}
