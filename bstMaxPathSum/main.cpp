#include <deque>
#include <iostream>
#include <string>
#include <vector>

/**
 * Definition for a binary tree node.
 */
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    ~TreeNode() = default;
};

int maxPathSum(TreeNode *root)
{
    if (root == nullptr)
    {
        std::cout << "nullptr" << std::endl;
        return 0;
    }

    int maxSum = 0;
    std::deque<TreeNode *> stack;
    TreeNode *current = root;

    while (current != nullptr || !stack.empty())
    {
        while (current != nullptr)
        {
            // visit node here for preorder
            stack.push_back(current);
            current = current->left;
        }

        current = stack.back();
        stack.pop_back();

        // visit the node here for inorder
        std::cout << current->val << std::endl;

        current = current->right;
    }

    return maxSum;
}

std::vector<TreeNode *> getNodes(int argc, char *argv[])
{
    std::vector<TreeNode *> nodes(argc, nullptr);

    for (int i{0}; i < argc; i++)
    {
        try
        {
            int nodeVal = std::stoi(std::string(argv[i]));

            nodes[i] = new TreeNode(nodeVal);
        }
        catch (const std::exception &e)
        {
            // std::cerr << e.what() << '\n';
        }
    }

    return nodes;
}

int main(int argc, char *argv[])
{
    auto nodes = getNodes(argc - 1, ++argv);

    for (uint i{0}; (i * 2 + 1) < nodes.size(); i++)
    {
        if ((i * 2 + 1) < nodes.size() && nodes[i] != nullptr)
        {
            nodes[i]->left = nodes[i * 2 + 1];
        }
        if ((i * 2 + 2) < nodes.size() && nodes[i] != nullptr)
        {
            nodes[i]->right = nodes[i * 2 + 2];
        }
    }

    std::cout << maxPathSum(nodes[0]) << std::endl;

    for (auto n : nodes)
    {
        if (n != nullptr)
        {
            delete n;
        }
    }

    return 0;
}