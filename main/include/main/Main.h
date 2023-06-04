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
    for (auto i = 1; i < argc; i++)
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

  auto tokensToInt(std::vector<std::string> tokens)
  {
    auto tokenInts = std::vector<int>{};
    try
    {
      for (const auto &t : tokens)
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

  auto tokensToInt(std::vector<std::vector<std::string>> tokens)
  {
    auto tokenInts = std::vector<std::vector<int>>{};

    for (auto &t : tokens)
    {
      tokenInts.push_back(tokensToInt(t));
    }

    return tokenInts;
  }

  auto argsToInt() { return tokensToInt(argV); }

  auto argsToTokens(const std::string delimiter)
  {
    auto tokens = std::vector<std::vector<std::string>>{};

    for (auto &t : argV)
    {
      auto tmpTok = std::vector<std::string>{};

      auto token =
          std::strtok(const_cast<char *>(t.c_str()), delimiter.c_str());
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
