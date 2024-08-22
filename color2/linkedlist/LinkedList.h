#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef int LL_VALUE_TYPE;

class LinkedList {
    class Node {
      public:
        int value;
        Node* next;
        Node(): Node(0) {}
        Node(): value(0), next(nullptr) {}
    };
    Node* head;
    Node* tail;
    unsigned int size;

    public:
    LinkedList();
    unsigned int length();
    void appendFront(int value);
    void appendBack(int value);
    void insert(int value, unsigned int idx);
    bool hasValue(int value);
};

LinkedList::LinkedList(): head(nullptr), tail(nullptr), size(0) {}

unsigned int LinkedList::length() {
    return size;
}

void LinkedList::appendFront(LL_VALUE_TYPE value) {
  Node* node = new Node(value);
  size++;
  if(head == nullptr) {
      //empty
      Node* node = new Node(value);
      head = node;
      tail = node;
  } else {
      //not empty
      node->next = head;
      head = node;
  }
}
void LinkedList::appendBack(LL_VALUE_TYPE value) {
  Node* node = new Node(value);
  size++;
  if(head == nullptr) {
      //empty
      Node* node = new Node(value);
      head = node;
      tail = node;
  } else {
      //not empty
      tail->next = node;
      tail = node;
  }
}

void LinkedList::insert(int value, unsigned int idx) {

}

bool LinkedList::hasValue(int value) {
  Node* current;
  while(current) {
    if (current->value == value) {

    }
  }
}

#endif
