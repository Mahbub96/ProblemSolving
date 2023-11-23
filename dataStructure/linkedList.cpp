#include <iostream>

class Node {
public:
  int data;
  Node *next;

  Node() { this->next = NULL; }
  Node(int data) {
    this->data = data;
    this->next = NULL;
  }
};

class LinkedList {

  Node *tail;

public:
  LinkedList() { this->tail->next = NULL; }

  void append(int value) {
    Node *temp = tail;
    while (tail->next) {
      this->tail = tail->next;
    }
    this->tail->next = new Node(value);
    this->tail = temp;
  }

  void show() {
    Node *temp;
    while (tail->next) {
      std::cout << tail->next->data << std::endl;
      tail = tail->next;
    }
    tail = temp;
  }
};

int main() {

  LinkedList l;

  l.append(10);
  l.append(12);
  l.append(13);
  l.append(14);

  l.show();

  return 0;
}
