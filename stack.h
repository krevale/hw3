#ifndef STACK_H
#define STACK_H

#include <vector>
#include <stdexcept>

// Use inheritance from std::vector (choose public/private) as appropriate
template <typename T>
class Stack : public std::vector<T>
{
public:
    Stack() : std::vector<T>(){}
    //~Stack() : std::vector;
    bool empty() const {
			return std::vector<T>::empty();
		}
    size_t size() const {
			return std::vector<T>::size();
		}
    void push(const T& item) {
			std::vector<T>::push_back(item);
		}
    void pop() {
			if (this->empty()) {
				throw std::underflow_error("underflow error");
			}

			std::vector<T>::pop_back();
		}  // throws std::underflow_error if empty
    const T& top() const {
			if (this->empty()) {
				throw std::underflow_error("underflow error");
			}

			return std::vector<T>::back();
		} // throws std::underflow_error if empty
    // Add other members only if necessary
};

//template <typename T>
//bool Stack::empty() {
//	return std::vector<T>::empty();
//}
//
//template <typename T>
//size_t Stack::size() const {
//	return std::vector<T>::size();
//}
//
//template <typename T>
//void Stack::push(const T& item) {
//	std::vector<T>::push_back(T);
//}
//
//template <typename T>
//void Stack::pop() {
//	if (this->empty()) {
//		throw std::underflow_error;
//	}
//
//	std::vector<T>::pop_back();
//}  // throws std::underflow_error if empty
//
//template <typename T>
//const T& Stack::top() const {
//	if (this->empty()) {
//		throw std::underflow_error;
//	}
//
//	return std::vector<T>::back();
//} // throws std::underflow_error if empty

#endif