#pragma once
#include <string>
#include <vector>

class LongestCommonSubstring
{
public:
    LongestCommonSubstring(const std::string &s1, const std::string &s2);
    std::string find();

private:
    void convertToLowerCase(const std::string &from, std::string &to);
    std::string str1;
    std::string str2;
    std::vector<std::vector<int>> dp;
};
