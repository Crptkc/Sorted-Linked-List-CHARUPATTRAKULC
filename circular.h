#ifndef CIRCULAR_H
#define CIRCULAR_H

#include <iostream>
#include <iomanip>

#include "node.h"

class LinkedList {
  NodePtr head; // head of linked list
  int size;

public:
  LinkedList();
  int remove(int value);
  int isEmpty();
  void insert(int value);
  void printList();
  int getSize();
  NodePtr getHead();
  ~LinkedList();

  /* With doubly linked list */
  void insertBetween(int value);
  void printReverseList();
  int removeDouble(int value);

  // Circular [two-way circular linked list]
  void insertCircular(int value);
  int removeCircular(int value);
  void printReverseListCircular();
};

LinkedList::LinkedList() {
  this->head = nullptr;
  size = 0;
}

LinkedList::~LinkedList() {
  std::cout << "Deleting all nodes" << std::endl;
  NodePtr temp = nullptr;
  NodePtr current = head;
  int i;
  for (i = 0; i < size; i++) {
    head = head->getNext();
    delete current;
    current = head;
  }
}

void LinkedList::insertCircular(int value) {
  NodePtr newNode = new Node(value);

  if (newNode != nullptr) {
    if (head == nullptr) {
      head = newNode;
      newNode->setNext(newNode);
      newNode->setPrev(newNode);
    } else {
      NodePtr current = head;
      while (current->getNext() != head && value > current->getNext()->getData()) {
        current = current->getNext();
      }
      newNode->setNext(current->getNext());
      current->getNext()->setPrev(newNode);
      newNode->setPrev(current);
      current->setNext(newNode);

      if (value < head->getData()) {
        head = newNode;
      }
    }
    ++size;
  } else {
    std::cout << value << " not inserted. No memory available." << std::endl;
  }
}

int LinkedList::removeCircular(int value) {
  NodePtr current = head;
  NodePtr temp = nullptr;

  if (current == nullptr) {
    return '\0';
  } else {
    if (value == head->getData()) {
      temp = head;
      head = head->getNext();

      if (head != nullptr) {
        head->setPrev(current->getPrev());
        current->getPrev()->setNext(head);
      } else {
        head = nullptr;
      }
      size--;
      delete temp;
      return value;
    } else {
      current = head->getNext();

      while (current != head) {
        if (value == current->getData()) {
          temp = current;
          current->getPrev()->setNext(current->getNext());
          current->getNext()->setPrev(current->getPrev());
          size--;
          delete temp;
          return value;
        }
        current = current->getNext();
      }
    }
  }

  return '\0';
}

void LinkedList::printReverseListCircular() {
  NodePtr currentPtr = head;

  if (size == 0 || head == nullptr) {
    std::cout << "List is empty." << std::endl;
  } else {
    std::cout << "The reverse list is:" << std::endl;
    while (currentPtr->getNext() != nullptr) {
      currentPtr = currentPtr->getNext();
    }
    for (int i = 0; i < size; i++) {
      currentPtr->print();
      std::cout << "  ->";
      currentPtr = currentPtr->getPrev();
    }
    std::cout << " NULL" << std::endl;
  }
}

int LinkedList::removeDouble(int value) {
  if (isEmpty()) {
    return '\0';
  }

  NodePtr currentPtr = head;

  while (currentPtr != nullptr && currentPtr->getData() != value) {
    currentPtr = currentPtr->getNext();
  }

  if (currentPtr == nullptr) {
    return '\0';
  }

  if (currentPtr->getPrev() != nullptr) {
    currentPtr->getPrev()->setNext(currentPtr->getNext());
  } else {
    head = currentPtr->getNext();
  }

  if (currentPtr->getNext() != nullptr) {
    currentPtr->getNext()->setPrev(currentPtr->getPrev());
  }

  int deletedValue = currentPtr->getData();
  delete currentPtr;
  --size;
  return deletedValue;
}

int LinkedList::getSize() {
  return size;
}

NodePtr LinkedList::getHead() {
  return head;
}

int LinkedList::isEmpty() {
  return head == nullptr;
}

void LinkedList::printList() {
  NodePtr currentPtr = head;

  if (size == 0 || head == nullptr) {
    std::cout << "List is empty." << std::endl;
  } else {
    std::cout << "The list is:" << std::endl;

    int i;
    for (i = 0; i < size; i++) {
      currentPtr->print();
      std::cout << "  ->";
      currentPtr = currentPtr->getNext();
    }
    std::cout << "NULL" << std::endl;
  }
}

void LinkedList::insertBetween(int value) {
  NodePtr newNode;
  NodePtr previousPtr;
  NodePtr currentPtr;

  newNode = new Node(value);

  if (newNode != nullptr) {
    previousPtr = nullptr;
    currentPtr = head;

    while (currentPtr != nullptr && value > currentPtr->getData()) {
      previousPtr = currentPtr;
      currentPtr = currentPtr->getNext();
    }

    if (previousPtr == nullptr) {
      newNode->setNext(head);
      if (head)
        head->setPrev(newNode);
      head = newNode;
    } else {
      previousPtr->setNext(newNode);
      newNode->setPrev(previousPtr);
      newNode->setNext(currentPtr);
      if (currentPtr)
        currentPtr->setPrev(newNode);
    }
    ++size;
  } else {
    std::cout << value << " not inserted. No memory available." << std::endl;
  }
}

void LinkedList::printReverseList() {
  NodePtr currentPtr = head;

  if (size == 0 || head == nullptr) {
    std::cout << "List is empty." << std::endl;
  } else {
    std::cout << "The reverse list is:" << std::endl;
    while (currentPtr->getNext() != nullptr) {
      currentPtr = currentPtr->getNext();
    }
    for (int i = 0; i < size; i++) {
      currentPtr->print();
      std::cout << "  ->";
      currentPtr = currentPtr->getPrev();
    }
    std::cout << " NULL" << std::endl;
  }
}

int LinkedList::remove(int value) {
  NodePtr previousPtr;
  NodePtr currentPtr;
  NodePtr tempPtr;

  if (value == head->getData()) {
    tempPtr = head;
    head = head->getNext();
    size--;

    delete tempPtr;

    return value;
  } else {
    previousPtr = head;
    currentPtr = head->getNext();

    while (currentPtr != nullptr && currentPtr->getData() != value) {
      previousPtr = currentPtr;
      currentPtr = currentPtr->getNext();
      if (currentPtr == head)
        currentPtr = nullptr;
    }

    if (currentPtr != nullptr) {
      tempPtr = currentPtr;
      previousPtr->setNext(currentPtr->getNext());
      currentPtr = currentPtr->getNext();

      delete tempPtr;
      size--;
      return value;
    }
  }

  return '\0';
}

void LinkedList::insert(int value) {
  NodePtr newNode;
  NodePtr previousPtr;
  NodePtr currentPtr;

  newNode = new Node(value);

  if (newNode != nullptr) {
    previousPtr = nullptr;
    currentPtr = head;

    while (currentPtr != nullptr && value > currentPtr->getData()) {
      previousPtr = currentPtr;
      currentPtr = currentPtr->getNext();
    }

    if (previousPtr == nullptr) {
      newNode->setNext(head);
      head = newNode;
    } else {
      previousPtr->setNext(newNode);
      newNode->setNext(currentPtr);
    }
    ++size;
  } else {
    std::cout << value << " not inserted. No memory available." << std::endl;
  }
}

#endif  // CIRCULAR_H
