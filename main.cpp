#include <iostream>

#include "src/hello.hpp"
#include "src/stack.hpp"
int main() {
  std::cout << hello() << std::endl;

  Stack<char> stack;
  stack.push('a');
  stack.push('b');
  stack.push('c');
  std::cout << stack.peek() << std::endl;
  std::cout << stack.pop() << std::endl;
  std::cout << stack.peek() << std::endl;
  stack.push('d');
  std::cout << stack.peek() << std::endl;
  std::cout << stack.pop() << std::endl;
  std::cout << stack.peek() << std::endl;



}
