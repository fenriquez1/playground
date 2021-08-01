#include <string>
#include <sstream>
#include <vector>
#include <main/Main.h>

//  Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    ListNode *result = new ListNode();
    ListNode *currentResult = result;
    ListNode *currentl1 = l1;
    ListNode *currentl2 = l2;
    int augend = 0;
    int addend = 0;
    int sum = 0;
    int carryOver = 0;

    while (currentl1 != nullptr || currentl2 != nullptr)
    {
        augend = 0;
        if (currentl1 != nullptr)
        {
            augend = currentl1->val;
            currentl1 = currentl1->next;
        }

        addend = 0;
        if (currentl2 != nullptr)
        {
            addend = currentl2->val;
            currentl2 = currentl2->next;
        }

        sum = augend + addend + carryOver;
        currentResult->val = sum % 10;

        if (currentl1 != nullptr || currentl2 != nullptr)
        {
            currentResult->next = new ListNode();
            currentResult = currentResult->next;
        }

        carryOver = sum / 10;
    }

    if (carryOver > 0)
    {
        currentResult->next = new ListNode(carryOver);
    }

    return result;
}

int main(int argc, char *argv[])
{
    Main lcMain(argc, argv);

    auto args = lcMain.argsToInt();
    uint l1Size = *(args.rbegin());
    std::cout << *args.rend() << std::endl;

    auto list1 = std::vector<int>(args.begin(), args.begin() + l1Size);
    auto list2 = std::vector<int>(args.begin() + list1.size(), args.end() - 1);

    auto l1 = new ListNode();
    auto l2 = new ListNode();

    ListNode *current = l1;

    for (auto it = list1.begin(); it != list1.end(); it++)
    {
        current->val = *it;
        if ((it + 1) != list1.end())
        {
            current->next = new ListNode();
        }
        std::cout << current->val << " ";
        current = current->next;
    }
    std::cout << "\n";

    current = l1;
    while (current != nullptr)
    {
        std::cout << current->val << " ";
        current = current->next;
    }
    std::cout << "\n";

    current = l2;
    for (auto it = list2.begin(); it != list2.end(); it++)
    {
        current->val = *it;
        if ((it + 1) != list2.end())
        {
            current->next = new ListNode();
        }
        std::cout << current->val << " ";
        current = current->next;
    }
    std::cout << "\n";

    current = l2;
    while (current != nullptr)
    {
        std::cout << current->val << " ";
        current = current->next;
    }
    std::cout << "\n";

    auto result = addTwoNumbers(l1, l2);
    current = result;

    while (current != nullptr)
    {
        std::cout << current->val << " ";
        current = current->next;
    }
    std::cout << "\n";

    current = result;
    while (current != nullptr)
    {
        result = result->next;
        delete current;
        current = result;
    }
    current = l1;
    while (current != nullptr)
    {
        l1 = l1->next;
        delete current;
        current = l1;
    }
    current = l2;
    while (current != nullptr)
    {
        l2 = l2->next;
        delete current;
        current = l2;
    }

    return 0;
}