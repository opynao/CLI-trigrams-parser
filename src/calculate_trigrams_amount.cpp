#include "calculate_trigrams_amount.h"

int calculateTrigramsAmount(LongestCommonSubstring &str)
{
    const std::string longestCommonSubstring = str.find();
    if (longestCommonSubstring.empty())
        return 0;
    const int finalLetters{2}; // Letters than doesn't participate in calculation of trigrams
    return longestCommonSubstring.size() - finalLetters;
}
