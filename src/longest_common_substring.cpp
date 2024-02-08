#include "longest_common_substring.h"
#include "utils.h"

#include <algorithm>
#include <cctype>

LongestCommonSubstring::LongestCommonSubstring(const std::string &s1, const std::string &s2)
{
    convertToLowerCase(s1, str1);
    convertToLowerCase(s2, str2);

    dp.resize(str1.length() + 1, std::vector<int>(str2.length() + 1, 0));
}

std::string LongestCommonSubstring::find()
{
    int maxLength = 0; // Length of longest common substring
    int endIndex = 0;  // Ending index of longest common substring in str1

    for (size_t i = 1; i <= str1.length(); ++i)
    {
        for (size_t j = 1; j <= str2.length(); ++j)
        {
            if (str1[i - 1] == str2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                if (dp[i][j] > maxLength)
                {
                    maxLength = dp[i][j];
                    endIndex = i - 1;
                }
            }
        }
    }

    // Extract longest common substring
    if (maxLength == 0)
    {
        return ""; // No common substring found
    }
    return str1.substr(endIndex - maxLength + 1, maxLength);
}

void LongestCommonSubstring::convertToLowerCase(const std::string &from, std::string &to)
{
    to.resize(from.size());
    std::transform(from.cbegin(), from.cend(), to.begin(),
                   [](unsigned char c)
                   { return std::tolower(c); });
}
