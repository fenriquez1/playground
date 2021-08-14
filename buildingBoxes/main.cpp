#include "main/Main.h"

int minimumBoxes(const int n)
{
    int floorCount = 0;
    int level = 0;
    int boxesToAdd = 1;
    int boxesAdded = 0;

    while (boxesAdded < n)
    {
        for (int b{boxesToAdd}; b > 0; b--)
        {
            if ((boxesAdded + b) <= n)
            {
                if (level++ == 0)
                {
                    floorCount += b;
                }
                boxesAdded += b;
            }
            else
            {
                if (level == 0)
                {
                    floorCount += (n - boxesAdded);
                }
                boxesAdded += (n - boxesAdded);
                break;
            }
        }

        level = 0;
        boxesToAdd++;
    }

    return floorCount;
}
int main(int argc, char *argv[])
{
    Main lcMain(argc, argv);

    auto args = lcMain.argsToInt();

    std::cout << minimumBoxes(args[0]) << std::endl;

    return 0;
}