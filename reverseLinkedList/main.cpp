#include <main/Main.h>
#include <iostream>

struct Node
{
    Node(int data) : data(data), next(nullptr) {}
    int data;
    Node *next;
};

void reverseLinkedList(Node *head)
{
    std::cout << head->data << " -> ";
    Node *current = head->next;

    if (current == nullptr)
    {
        return;
    }
    else
    {
        reverseLinkedList(current);
        current->next = head;
    }

    // std::cout << current->data << " -> ";
    head->next = nullptr;
}

int main(int argc, char *argv[])
{
    Main lMain(argc, argv);

    auto args = lMain.argsToInt();

    Node *current = nullptr;
    Node *head = nullptr;

    for (auto n : args)
    {
        if (current == nullptr)
        {
            current = new Node(n);
            head = current;
        }
        else
        {
            current->next = new Node(n);
            current = current->next;
        }

        // std::cout << current->data << " -> ";
    }

    reverseLinkedList(head);
    std::cout << std::endl;

    while (current != nullptr)
    {
        head = current;
        current = head->next;
        std::cout << head->data << " -> ";
        delete head;
    }

    return 0;
}