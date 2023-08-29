#include <string>
#include <sstream>
#include <vector>
#include <main/Main.h>

int reverseInteger(int x)
{
    auto result = 0;
    auto sign = 1;

    try
    {
        auto xString = std::to_string(x);

        if (x < 0)
        {
            sign *= -1;
            xString = xString.substr(1);
        }

        std::stringstream ss;

        for (auto it = xString.rbegin(); it != xString.rend(); it++)
        {
            ss << *it;
        }

        result = std::stoi(ss.str());
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        result = 0;
    }

    return result * sign;
}

int main(int argc, char *argv[])
{
    Main lcMain(argc, argv);

    auto args = lcMain.argsToInt();

    std::cout << args[0] << std::endl;
    std::cout << reverseInteger(args[0]) << std::endl;

    return 0;
}