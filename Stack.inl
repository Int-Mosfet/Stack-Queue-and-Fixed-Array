// -*- C++ -*-
// $Id: Stack.inl 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge: Jason Wignot
//
// I pledge that I have neither given nor received any help on
// this assignment.

//
// size
//
template <typename T>
inline
size_t Stack <T>::size (void) const
{
	return stack_top_;
}

//
// top
//
template <typename T>
inline
T Stack <T>::top (void) const
{
	// if not empty, return top of stack
	if (!is_empty())
	{

		// I use the "stack_top_" variable as the size
		// of stack as well, so if I don't subtract 1
		// it will go out of bounds
		return (stack_.get(stack_top_ - 1));
	}
	//else, stack is empty

	try{
		throw std::exception();
	}
	catch (std::exception &e) {
		std::cout << "Stack is empty" << std::endl;
	}

	return -1;
}

//
// is_empty
//
template <typename T>
inline
bool Stack <T>::is_empty (void) const
{
	//only need this line to check
	return(stack_top_ == 0);
}
