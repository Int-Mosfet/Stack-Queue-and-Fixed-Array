// $Id: Fixed_Array.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:  Jason Wignot
//
// I pledge that I have neither given nor received any help
// on this assignment.

#include "Fixed_Array.h"
#include <stdexcept>       // for std::out_of_bounds exception

//
// Fixed_Array, Default Constructor
//
template <typename T, size_t N>
Fixed_Array <T, N>::Fixed_Array (void) : 
Base_Array<T>(N), 
cur_size_(0),
max_size_(0)
{
	
}

//
// Fixed_Array, Copy Constructor
//
template <typename T, size_t N>
Fixed_Array <T, N>::Fixed_Array(const Fixed_Array <T, N> & arr) :
Base_Array<T>(arr),
cur_size_(arr.size()),
max_size_(arr.max_size())
{
	
}

//
// Fixed_Array
//
template <typename T, size_t N>
template <size_t M>
Fixed_Array <T, N>::Fixed_Array (const Fixed_Array <T, M> & arr) :
Base_Array<T>(arr),
cur_size_(arr.size()),
max_size_(arr.max_size())
{
	
}

//
// Fixed_Array, Initializing Constructor
//
template <typename T, size_t N>
Fixed_Array <T, N>::Fixed_Array (T fill) : 
Base_Array<T>(N, fill)
{
	
}

//
// ~Fixed_Array
//
template <typename T, size_t N>
Fixed_Array <T, N>::~Fixed_Array (void)
{
	
}

//
// operator =
//
template <typename T, size_t N>
const Fixed_Array <T, N> & Fixed_Array <T, N>::operator = (const Fixed_Array <T, N> & rhs)
{
	//check for self assignment first
	if (this == &rhs)
	{
		return *this;
	}
	//check if same, if so, return
	if (data_ == rhs.data_)
	{
		return *this;
	}
	//assignment operator, need to copy one side
	//to other side
	for (unsigned int i = 0; i < cur_size_; i++)
	{
		rhs.data_[i] = data_[i];
	}
	return *this;
}

//
// operator =
//
template <typename T, size_t N>
template <size_t M>
const Fixed_Array <T, N> & Fixed_Array <T, N>::operator = (const Fixed_Array <T, M> & rhs)
{
	//check for self assignment first
	if (this == &rhs)
	{
		return *this;
	}
	//check if same, if so, return
	if (data_ == rhs.data_)
	{
		return *this;
	}
	//assignment operator, need to copy one side
	//to other side
	for (unsigned int i = 0; i < cur_size_; i++)
	{
		rhs.data_[i] = data_[i];
	}
	return *this;
}
