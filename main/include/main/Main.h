#pragma once

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

    std::vector<int> argsToInt()
    {
        std::vector<int> args;
        try
        {
            for (const auto t : argV)
            {
                args.push_back(stoi(t));
            }
        }
        catch (const std::exception &ex)
        {
            std::cerr << ex.what() << std::endl;
        }

        return args;
    }

private:
    std::vector<std::string> argV;
};
