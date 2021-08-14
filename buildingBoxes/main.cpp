#include "main/Main.h"

int minimumBoxes(const int n)
{
    int floorCount = 0;
    int boxesToAdd = 1;
    int boxesAdded = 0;

    while (boxesAdded < n)
    {
        for (int b{1}; b <= boxesToAdd; b++)
        {
            if ((boxesAdded + b) <= n)
            {
                floorCount++;
                boxesAdded += 1 + (b - 1);
            }
            else if ((boxesAdded + 1) <= n)
            {
                floorCount++;
                boxesAdded += 1 + (n - (boxesAdded + 1));
                break;
            }
            else
            {
                break;
            }
        }

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