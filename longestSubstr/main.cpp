#include <iostream>
#include <string>
#include <string.h>
#include <sstream>
#include <vector>

int lengthOfLongestSubstring(const std::string s)
{
    char asciiChars[127];
    auto tmpSubstr = std::string();

    memset(asciiChars, 0, sizeof(char) * 127);

    uint startSubstrPos = 0;
    uint endSubstrPos = 0;
    auto substrIt = s.begin();
    auto substr = std::string{};
    uint nextCharValue = 0;
    size_t newStart = 0;

    while (substrIt != s.end())
    {
        nextCharValue = *substrIt;

        if (asciiChars[nextCharValue] != 0)
        {
            // repeat char found

            tmpSubstr = s.substr(startSubstrPos, endSubstrPos - startSubstrPos);

            if (tmpSubstr.size() > substr.size())
            {
                substr = tmpSubstr;
            }

            // find next instance of repeat char and set start to 1 char ahead of repeat
            newStart = s.find(*substrIt, startSubstrPos);

            if (newStart != std::string::npos)
            {
                std::string removeChars;

                if (startSubstrPos == newStart)
                {
                    removeChars = s.substr(startSubstrPos, 1);
                }
                else
                {
                    removeChars = s.substr(startSubstrPos, newStart - startSubstrPos + 1);
                }

                for (auto c : removeChars)
                {
                    asciiChars[static_cast<uint>(c)] = 0;
                }

                startSubstrPos = newStart + 1;
                tmpSubstr = s.substr(startSubstrPos, endSubstrPos - startSubstrPos + 1);
                asciiChars[nextCharValue] = 1;
            }
        }
        else
        {
            // mark char as found
            asciiChars[nextCharValue] = 1;

            tmpSubstr = tmpSubstr + *substrIt;

            if (tmpSubstr.size() > substr.size())
            {
                substr = tmpSubstr;
            }
        }

        substrIt++;
        endSubstrPos++;
    }

    return substr.size();
}

int main(int argc, char *argv[])
{
    std::string s(" ");

    if (argc == 2)
    {
        s = std::string(argv[1]);
    }

    std::cout << s << std::endl;

    std::cout << lengthOfLongestSubstring(s) << std::endl;

    return 0;
}