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
        return 0;
    }

    static int maxSum = 0x80000000;
    static TreeNode *current = root;

    int lSum = maxPathSum(root->left);
    int rSum = maxPathSum(root->right);

    int op1 = lSum + rSum + root->val;
    int op2 = lSum + root->val;
    int op3 = rSum + root->val;

    if (op1 > maxSum)
    {
        maxSum = op1;
    }

    if (current->val == root->val)
    {
        return maxSum;
    }

    return std::max(op2, op3);
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