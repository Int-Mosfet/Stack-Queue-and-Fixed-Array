
#include "Stack.h"
#include <stdexcept>         // for std::out_of_bounds exception

#define STACK_SIZE_MAX 4294967295

//
// Stack Default Constructor
//
template <typename T>
Stack <T>::Stack(void) :
stack_top_(0),
stack_(0)
{

}

//
// Stack Copy Constructor
//

template <typename T>
Stack <T>::Stack(const Stack <T> & stack) :
stack_top_(stack.stack_top_),
stack_(stack.stack_)
{

}

//
// ~Stack Destructor
//
template <typename T>
Stack <T>::~Stack(void)
{
	// Array base class will handle destruction,
	// but I could cleanse memory beforehand
}

//
// push
//
template <typename T>
void Stack <T>::push(T element)
{
	// Only would happen in heavy duty usage...
	// but I'm checking for too large a stack.
	// 4,294,967,295 seems large enough for now.
	if (stack_top_ >= STACK_SIZE_MAX || stack_.size() >= STACK_SIZE_MAX)
	{
		try{
			throw std::out_of_range("Stack is its max size");
		}
		catch (std::out_of_range &e) {
			std::cout << "Max size exceeded" << std::endl;
		}

	}

	// Anytime an element is pushed,
	// first resize the stack to make
	// space for that element
	stack_.resize(1 + stack_top_);

	// Set the element at the stack top
	stack_.set(stack_top_, element);

	// Update index
	stack_top_++;
}

//
// pop
//
template <typename T>
void Stack <T>::pop(void)
{
	// Supposed to throw an error if the stack is empty
	if (is_empty())
	{
		try{
			throw std::exception();
		}
		catch (std::exception &e) {
			std::cout << "Trying to pop from empty stack" << std::endl;
		}

	}

	// Pop an element off the top of stack
	stack_top_--;

	// Resize stack with new size
	stack_.resize(stack_top_);
}

//
// operator =
//
template <typename T>
const Stack <T> & Stack <T>::operator = (const Stack <T> & rhs)
{
	// Check for self-assignment first
	if (this == &rhs)
	{
		return *this;
	}

	// Check if same, if so, return
	if (stack_ == rhs.stack_)
	{
		return *this;
	}

	// Resize the array to make sure it's the same size
	stack_.resize(rhs.size());

	// Copy one side to the other
	for (unsigned int i = 0; i < stack_.size(); i++)
	{
		stack_[i] = rhs.stack_[i];
	}
	return *this;
}

//
// clear
//
template <typename T>
void Stack <T>::clear(void)
{
	// Set ToS to 0, then clear the stack memory space with
	// only one resize.

	stack_top_ = 0;
	stack_.resize(stack_top_);
}