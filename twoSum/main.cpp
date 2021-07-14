#include <iostream>
#include <unordered_map>
#include <vector>
#include <main/Main.h>

std::vector<int> twoSum(std::vector<int> &nums, int target)
{
    std::vector<int> result;

    std::unordered_map<int, int> hashMap;

    for (int i = 0; i < nums.size(); i++)
    {
        int diff = target - nums[i];

        auto it = hashMap.find(diff);

        if (it != hashMap.end())
        {
            std::cout << it->first << ":" << it->second << std::endl;

            result.push_back(i);
            result.push_back(it->second);
            break;
        }

        hashMap[nums[i]] = i;

        std::cout << nums[i] << ":" << i << std::endl;

        it = hashMap.find(diff);

        if (it != hashMap.end() && i != it->second)
        {
            std::cout << it->first << ":" << it->second << std::endl;

            result.push_back(i);
            result.push_back(it->second);
            break;
        }
    }

    return result;
}

int main(int argc, char *argv[])
{
    Main lcMain(argc, argv);

    auto args = lcMain.argsToInt();

    auto target = args.rbegin();
    auto nums = std::vector<int>(args.begin(), args.end() - 1);

    std::cout << "nums: ";
    for (const auto n : nums)
    {
        std::cout << n << " ";
    }

    std::cout << "\ttarget: " << *target << std::endl;

    auto result = twoSum(nums, *target);

    std::cout << "[";

    for (auto n : result)
    {
        std::cout << n << " ";
    }

    std::cout << "]" << std::endl;

    return 0;
}
