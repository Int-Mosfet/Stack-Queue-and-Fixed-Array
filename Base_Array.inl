// -*- C++ -*-
// $Id: Array.inl 828 2011-02-07 14:21:52Z hillj $

// Honor Pledge:  Jason Wignot
//
// I pledge that I have neither given nor received any help
// on this assignment.

//
// size
//
template <typename T>
inline
size_t Base_Array <T>::size(void) const
{
	//just return current size
	return cur_size_;
}

//
// max_size
//
template <typename T>
inline
size_t Base_Array <T>::max_size(void) const
{
	//just return max size
	return max_size_;
}
