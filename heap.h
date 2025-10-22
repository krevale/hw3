#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>

#include <vector>
#include <algorithm>

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator()) {
    ary = m;
		pc = c;
  }

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap() {}

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item) {
    vec.push_back(item);

		int n = (int)vec.size();

		int idx = n - 1;

		if (ary < 2 || idx <= 0) {
			return;
		}

		while (idx > 0) {
			int parent = (idx - 1) / ary;
			if (pc(vec[idx], vec[parent])) {
				std::swap(vec[idx], vec[parent]);
				idx = parent;
			} else {
				break;
			}
		}
  }

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const {
    if (vec.empty()) {
      throw std::underflow_error("underflow error");
    }

    return vec[0];
  }

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop() {
    if (vec.empty()) {
      throw std::underflow_error("underflow error");
    }

		std::swap(vec[0], vec[vec.size()-1]);
		vec.pop_back();

		int n = (int)vec.size();
		if (n <= 1) {
			return;
		}

		int idx = 0;
		while (true) {
			int firstChild = ary * idx + 1;
			if (firstChild >= n) {
				break;
			}

			int best = firstChild;
			int lastChild = firstChild + ary - 1;
			if (lastChild >= n) {
				lastChild = n - 1;
			}
			for (int i = firstChild + 1; i <= lastChild; ++i) {
				if (pc(vec[i], vec[best])) {
					best = i;
				}
			}

			if (pc(vec[best], vec[idx])) {
				std::swap(vec[idx], vec[best]);
				idx = best;
			} else {
				break;
			}
		}
  }

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const {
		return vec.empty();
	}

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const {
		return vec.size();
	}

private:
  /// Add whatever helper functions and data members you need below

  std::vector<T> vec;

  int ary;

	PComparator pc;

};

// Add implementation of member functions here

// We will start top() for you to handle the case of 
// calling top on an empty heap
//template <typename T, typename PComparator>
//T const & Heap<T,PComparator>::top() const
//{
//  // Here we use exceptions to handle the case of trying
//  // to access the top element of an empty heap
//  if(empty()){
//    // ================================
//    // throw the appropriate exception
//    // ================================
//
//
//  }
//  // If we get here we know the heap has at least 1 item
//  // Add code to return the top element
//
//
//
//}
//
//
//// We will start pop() for you to handle the case of 
//// calling top on an empty heap
//template <typename T, typename PComparator>
//void Heap<T,PComparator>::pop()
//{
//  if(empty()){
//    // ================================
//    // throw the appropriate exception
//    // ================================
//
//
//  }
//
//
//
//}



#endif

