#pragma once

#include <cstring>
#include <iostream>
#include <string>
#include <vector>

class Main
{
public:
    Main(int argc, char *argv[])
    {
        for (int i = 1; i < argc; i++)
        {
            argV.push_back(argv[i]);
        }
    }

    ~Main() = default;
    Main() = delete;
    Main(const Main &) = delete;
    Main(Main &&) = delete;
    Main &operator=(const Main &) = delete;
    Main &operator=(Main &&) = delete;

    std::vector<int> tokensToInt(std::vector<std::string> tokens)
    {
        std::vector<int> tokenInts;
        try
        {
            for (const auto t : tokens)
            {
                tokenInts.push_back(stoi(t));
            }
        }
        catch (const std::exception &ex)
        {
            std::cerr << ex.what() << std::endl;
        }

        return tokenInts;
    }

    std::vector<std::vector<int>> tokensToInt(std::vector<std::vector<std::string>> tokens)
    {
        std::vector<std::vector<int>> tokenInts;

        for (auto t : tokens)
        {
            tokenInts.push_back(tokensToInt(t));
        }

        return tokenInts;
    }

    std::vector<int> argsToInt()
    {
        return tokensToInt(argV);
    }

    std::vector<std::vector<std::string>> argsToTokens(const std::string delimiter)
    {
        std::vector<std::vector<std::string>> tokens;

        for (auto t : argV)
        {
            std::vector<std::string> tmpTok;

            char *token = std::strtok(const_cast<char *>(t.c_str()), delimiter.c_str());
            while (token)
            {
                tmpTok.push_back(std::string(token));
                token = std::strtok(nullptr, delimiter.c_str());
            }

            tokens.push_back(tmpTok);
        }

        return tokens;
    }

private:
    std::vector<std::string> argV;
};
