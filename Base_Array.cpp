// $Id: Array.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:  Jason Wignot
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#include "Base_Array.h"
#include <stdexcept>         // for std::out_of_bounds exception

//
// Array
//
template <typename T>
Base_Array <T>::Base_Array(void) :
cur_size_(0),
max_size_(0),
data_(nullptr)
{
	
}

//
// Array (size_t)
//
template <typename T>
Base_Array <T>::Base_Array(size_t length) :
cur_size_(length),
max_size_(length),
data_(new T[length])
{
	
}

//
// Array (size_t, char)
//
template <typename T>
Base_Array <T>::Base_Array(size_t length, T fill) :
cur_size_(length),
max_size_(length),
data_(new T[length])
{
	Base_Array::fill(fill);
}

//
// Array (const Array &) //Copy Constructor
//
template <typename T>
Base_Array <T>::Base_Array(const Base_Array <T> & array) :
cur_size_(array.size()),
max_size_(array.max_size()),
data_(nullptr)
{
	data_ = new T[cur_size_];
	//initializing the array
	for (unsigned int i = 0; i < cur_size_; i++)
	{
		data_[i] = array.data_[i];
	}
}

//
// ~Array
//
template <typename T>
Base_Array <T>::~Base_Array(void)
{
	delete[] data_;
}

//
// operator =
//
template <typename T>
const Base_Array <T> & Base_Array <T>::operator = (const Base_Array <T> & rhs)
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
	//resize the array to make sure it's the same size
	resize(rhs.cur_size_);

	//assignment operator, need to copy one side
	//to other side
	for (unsigned int i = 0; i < cur_size_; i++)
	{
		rhs.data_[i] = data_[i];
	}
	return *this;
}

//
// operator []
//
template <typename T>
T & Base_Array <T>::operator [] (size_t index)
{
	//if index at bounds or greater
	if (index >= cur_size_)
	{
		throw std::out_of_range("OUT OF RANGE");
	}
	//else
	//return value at index
	return data_[index];
}

//
// operator [] 
//
template <typename T>
const T & Base_Array <T>::operator [] (size_t index) const
{
	if (index >= cur_size_)
	{
		throw std::out_of_range("OUT OF RANGE");
	}
	//else
	//return value at index
	return data_[index];
}

//
// get
//
template <typename T>
T Base_Array <T>::get(size_t index) const
{
	if (index >= cur_size_)
	{
		cout << "GET ERROR1" << endl;
		throw std::out_of_range("OUT OF RANGE");
	}
	//else
	//return value at index
	return data_[index];
}

//
// set
//
template <typename T>
void Base_Array <T>::set(size_t index, T value) //<--orig
{
	if (index >= cur_size_)
	{
		throw std::out_of_range("OUT OF RANGE");
	}
	//else
	//set the value at the index
	data_[index] = value;
}

//
// find (char)
//
template  <typename T>
int Base_Array <T>::find(T value) const
{
	//search for the value, return index if found
	for (unsigned int i = 0; i < cur_size_; i++)
	{
		if (data_[i] == value)
		{
			return i;
		}
	}
	//else return -1
	return -1;
}

//
// find (char, size_t) 
//
template <typename T>
int Base_Array <T>::find(T val, size_t start) const
{
	if (start >= cur_size_)
	{
		throw std::out_of_range("OUT OF RANGE");
	}
	//start searching at specified index
	for (size_t i = start; i < cur_size_; i++)
	{
		if (data_[i] == val)
		{
			return i;
		}
	}
	//else return -1
	return -1;
}

//
// operator ==
//
template <typename T>
bool Base_Array <T>::operator == (const Base_Array <T> & rhs) const
{
	//I need to check if they're the same first
	if (this == &rhs)
	{
		return true;
	}
	//if they aren't same size, then
	//they aren't equal
	if (cur_size_ != rhs.size())
	{
		return false;
	}
	//start by comparing element by element
	for (unsigned int i = 0; i < cur_size_; i++)
	{
		if (data_[i] != rhs.data_[i])
		{
			return false;
		}
	}
	//if above loop and checks don't
	//return false then arrays are equal
	//so return true if reach this point
	return true;
}

//
// operator !=
//
template <typename T>
bool Base_Array <T>::operator != (const Base_Array <T> & rhs) const
{
	//I need to check if they're the same first
	if (this == &rhs)
	{
		return false;
	}
	//if not same size
	//then they aren't equal
	if (cur_size_ != rhs.size())
	{
		return true;
	}

	for (unsigned int i = 0; i < cur_size_; i++)
	{
		if (data_[i] != rhs.data_[i])
		{
			return true;
		}
	}
	//if above loop doesn't return true
	//then arrays are equal, so return 
	//false because this is not equal checker
	return false;
}

//
// fill
//
template <typename T>
void Base_Array <T>::fill(T value)
{
	//fill in array of the current size
	//with specified value
	for (unsigned int i = 0; i < cur_size_; i++)
	{
		data_[i] = value;
	}
}

//
// reverse
//
template <typename T>
void Base_Array <T>::reverse(void)
{
	//temp T for swapping elements around
	T temp_T;

	cout << "BASE ARRAY REVERSE" << endl;

	//swap each element, starting with first and last one
	//divide by 2 since 2 values swap places
	//we only need to loop for half the amount then

	for (unsigned int i = 0; i < (cur_size_ / 2); i++)
	{
		//do the swap algorithm

		temp_T = data_[cur_size_ - i - 1];
		data_[cur_size_ - i - 1] = data_[i];
		data_[i] = temp_T;
	}
}