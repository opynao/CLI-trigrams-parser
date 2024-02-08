#include "longest_common_substring.h"
#include "calculate_trigrams_amount.h"
#include "utils.h"

#include <string>
#include <iostream>

int main()
{
    std::string str1, str2;

    std::cout << "Enter the first string: ";
    std::getline(std::cin, str1);

    std::cout << "Enter the second string: ";
    std::getline(std::cin, str2);
    LongestCommonSubstring lcs(str1, str2);
    std::cout << "Amount of consecutive trigrams: " << calculateTrigramsAmount(lcs) << std::endl;
}
