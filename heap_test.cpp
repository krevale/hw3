#include <iostream>
#include <algorithm> // for std::swap

// Include your header (with the space in the filename)
#include "heap.h"

int main() {
  try {
    // Default: binary MIN-heap
    Heap<int> h2;
    int vals[] = {7, 3, 5, 1, 9, 2};
    for (int v : vals) h2.push(v);

    std::cout << "min-heap order: ";
    while (!h2.empty()) {
      std::cout << h2.top() << ' ';
      h2.pop();
    }
    std::cout << "\n";

    // 3-ary MIN-heap
    Heap<int> h3(3);
    for (int v : vals) h3.push(v);

    std::cout << "3-ary min-heap order: ";
    while (!h3.empty()) {
      std::cout << h3.top() << ' ';
      h3.pop();
    }
    std::cout << "\n";

    // MAX-heap (use greater<> so "larger" has priority)
    Heap<int, std::greater<int>> hMax(2);
    for (int v : vals) hMax.push(v);

    std::cout << "max-heap order: ";
    while (!hMax.empty()) {
      std::cout << hMax.top() << ' ';
      hMax.pop();
    }
    std::cout << "\n";

    // Underflow test: popping an empty heap should throw
    try {
      Heap<int> empty;
      empty.pop();
    } catch (const std::underflow_error& e) {
      std::cout << "Caught underflow_error on pop(): " << e.what() << "\n";
    }
  } catch (const std::exception& e) {
    std::cerr << "Unexpected error: " << e.what() << "\n";
    return 1;
  }
  return 0;
}
