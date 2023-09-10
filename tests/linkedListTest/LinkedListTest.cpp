#include <cstddef>
#include <cstdlib>
#include <gtest/gtest.h>
#include <linkedList/LinkedList.h>
#include <linkedList/ListNode.h>
#include <vector>

TEST(ListNodeTest, CreatesListNode) {
  auto nodeValue = std::rand();
  ListNode<int> ln1{nodeValue};
  ListNode<int> ln2{nodeValue};
  EXPECT_EQ(ln1, ln2);
  EXPECT_TRUE(ln1.getNext() == nullptr);
}

TEST(LinkedListTest, CreatesEmptyList) {
  LinkedList<int> ll;

  EXPECT_TRUE(ll.getHead() == nullptr);
}

TEST(LinkedListTest, CreateSingleNodeList) {
  auto nodeValue = std::rand();
  LinkedList<int> ll{nodeValue};

  EXPECT_EQ(nodeValue, ll.getHead()->getValue());
  EXPECT_EQ(ll.getTail(), ll.getHead());
}

TEST(LinkedListTest, CreateMultiNodeList) {
  auto nums = std::vector<int>{};

  for (auto i = 0; i <= 10; i++) {
    nums.push_back(std::rand());
  }

  LinkedList<int> ll;
  for (auto num : nums) {
    ll.addNode(num);
  }

  EXPECT_EQ(nums.size(), ll.size());

  auto current = ll.getHead();

  for (auto num : nums) {
    EXPECT_EQ(num, current->getValue());
    current = current->getNext();
  }

  EXPECT_TRUE(current == nullptr);
}