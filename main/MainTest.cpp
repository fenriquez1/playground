#include <cstddef>
#include <gtest/gtest.h>
#include <main/Main.h>
#include <vector>

TEST(MainTest, ParsesArgvIntegerList)
{
    char main[] = "main";
    char one[] = "1";
    char two[] = "2";
    char three[] = "3";
    char *argv[] = {main,one,two,three};
    // Given
    Main mainTest{4, argv};
    // Expect vector to be [1,2,3]
    auto expectedTokens = std::vector<int>{1,2,3};
    auto actualTokens = mainTest.argsToInt();
    EXPECT_EQ(expectedTokens, actualTokens);
}
