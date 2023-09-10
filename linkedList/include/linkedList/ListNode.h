#pragma once
#include <memory>

template <typename T> class ListNode {
public:
  explicit ListNode(const T &t) : value{t}, next{nullptr} {}
  ListNode() = delete;
  ~ListNode() = default;
  ListNode(const ListNode &) = default;
  ListNode(ListNode &&) = delete;
  ListNode &operator=(const ListNode &) = delete;
  ListNode &operator=(ListNode &&) = delete;

  auto getNext() { return this->next; }
  const auto getValue() const { return this->value; }
  void setNext(std::shared_ptr<ListNode<T>> ln) { this->next = ln; }

  auto operator==(const ListNode<T> &listNode) const {
    return this->value == listNode.value;
  }

private:
  T value;
  std::shared_ptr<ListNode<T>> next;
};
