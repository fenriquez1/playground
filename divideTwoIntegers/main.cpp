#include <main/Main.h>

int divideTwoIntegers(int32_t dividend, int32_t divisor)
{
    constexpr int32_t minInt = 0x80000000;
    constexpr int32_t maxInt = 0x7fffffff;
    constexpr uint32_t Int32Bits = 31;

    uint32_t quot = 0;
    uint32_t lDividend;
    uint32_t lDivisor;
    uint32_t tmpDividend;
    uint32_t dividendLeftBit = 0;
    uint32_t divisorLeftBit = 0;
    int32_t shiftCount;
    int32_t sign = 1;

    if (dividend < 0)
    {
        if (dividend == minInt)
        {
            lDividend = 0x80000000;
        }
        else
        {
            lDividend = dividend * -1;
        }
        sign *= -1;
    }
    else
    {
        lDividend = dividend;
    }

    if (divisor < 0)
    {
        if (divisor == minInt)
        {
            lDivisor = 0x80000000;
        }
        else
        {
            lDivisor = divisor * -1;
        }
        sign *= -1;
    }
    else
    {
        lDivisor = divisor;
    }

    if (lDividend < lDivisor)
    {
        return 0;
    }

    if (lDividend & 0x80000000 && lDivisor == 1 && sign == 1)
    {
        return maxInt;
    }

    for (uint32_t i{0}; i <= Int32Bits; i++)
    {
        if (lDividend >> i == 1)
        {
            dividendLeftBit = i;
        }

        if (lDivisor >> i == 1)
        {
            divisorLeftBit = i;
        }
    }

    shiftCount = dividendLeftBit - divisorLeftBit;

    tmpDividend = lDividend >> shiftCount;

    while (shiftCount-- >= 0)
    {
        quot = quot << 1;

        if (tmpDividend >= lDivisor)
        {
            quot += 1;
            tmpDividend -= lDivisor;
        }

        tmpDividend = tmpDividend << 1;

        if (shiftCount < 0)
        {
            break;
        }

        tmpDividend += (lDividend >> shiftCount) & 1;
    }

    if (quot & minInt)
    {
        return minInt;
    }

    return (sign * quot);
}

int main(int argc, char *argv[])
{
    Main lcMain(argc, argv);

    auto args = lcMain.argsToInt();

    std::cout << divideTwoIntegers(args.at(0), args.at(1)) << std::endl;

    return 0;
}