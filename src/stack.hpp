#include <iostream>
#include <ostream>
// #include "dish.hpp"

// #include "../cmake-build-debug/_deps/catch2-src/src/catch2/internal/catch_windows_h_proxy.hpp"
//
// Created by daisy on 4/28/2026.
//


#ifndef A_STACK_OF_DISHES_STACK_HPP
#define A_STACK_OF_DISHES_STACK_HPP
const int MAX_SIZE = 100;
template <typename S>

class Stack {
  private:
  S array[MAX_SIZE];
  S *top;
  S *start;

  public:
  Stack() {
    top = array;
    start = array;
  }

  bool isEmpty() {
    return top == start;
  }
  bool isFull() {
    return (start + MAX_SIZE == top);
  }
  int size() {
    return top - start;
  }
  void push(S newItem) {
    if (isFull()) {
      std::cout << "Stack is full." << std::endl;
      return;
    }
     *top++ = newItem;
  }
  S pop() {
    if (!isEmpty()) {
      top--;
      S temp = *top;
      return temp;
    }
    std::cout << "Stack is empty." << std::endl;
    throw "Stack is empty.";
  }
  S peek() {
    if (!isEmpty()) {
      top--;
      S temp = *top;
      top++;
      return temp;
    }
    std::cout << "Stack is empty." << std::endl;
    throw "Stack is empty.";
  }
  void clear() {
    top = array;
    start = array;

  }
};


#endif //A_STACK_OF_DISHES_STACK_HPP