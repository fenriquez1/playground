#pragma once

#include <linkedList/ListNode.h>
#include <memory>

template <typename T> class LinkedList {
public:
  LinkedList() : m_size{0} {}
  explicit LinkedList(const T &t)
      : m_size{0}, head{new ListNode<T>{t}}, tail{head} {}
  ~LinkedList() = default;
  void addNode(const T &t) {
    if (this->head == nullptr) {
      this->head.reset(new ListNode<T>{t});
      this->tail = this->head;
    } else {
      std::shared_ptr<ListNode<T>> newTail{new ListNode<T>{t}};
      this->tail->setNext(newTail);
      this->tail = newTail;
    }
    this->m_size++;
  }
  auto getHead() const { return this->head; }
  auto getTail() const { return this->tail; }
  auto size() const { return this->m_size; }

private:
  std::size_t m_size;
  std::shared_ptr<ListNode<T>> head;
  std::shared_ptr<ListNode<T>> tail;
};