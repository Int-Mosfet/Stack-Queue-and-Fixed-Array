// $Id: Array.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:  Jason Wignot
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#include "Array.h"
#include <stdexcept>         // for std::out_of_bounds exception

//
// Array
//
template <typename T>
Array <T>::Array(void) : 
Base_Array <T>()  //inherit from base array class
{
	
}

//
// Array (size_t)
//
template <typename T>
Array <T>::Array(size_t length) : 
Base_Array <T>(length)
{
	
}

//
// Array (size_t, char)
//
template <typename T>
Array <T>::Array(size_t length, T fill) : 
Base_Array <T>(length, fill)
{
	
}

//
// Array (const Array &) //Copy Constructor
//
template <typename T>
Array <T>::Array(const Array <T> & array) : 
Base_Array <T>(array)
{
	
}

//
// ~Array
//
template <typename T>
Array <T>::~Array (void)
{
	
}

//
// operator =
//
template <typename T>
const Array <T> & Array <T>::operator = (const Array <T> & rhs)
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
T & Array <T>::operator [] (size_t index)
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
const T & Array <T>::operator [] (size_t index) const
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
T Array <T>::get (size_t index) const
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
// set
//
template <typename T>
void Array <T>::set (size_t index, T value) //<--orig
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
// resize
//
template <typename T>
void Array <T>::resize (size_t new_size)
{
	if (new_size < cur_size_)
	{
		//only need to change the current size
		//array will be truncated with new size
		cur_size_ = new_size;
	}

	else if (new_size > cur_size_)
	{
		//temp array to hold original contents
		T * temp_arr;
		//make temp array with new size, not current size!
		temp_arr = new T[new_size];
		//temp value for swapping pointers
		T * temp_ptr = nullptr;
		//copy original values over into temp array
		for (unsigned int i = 0; i < cur_size_; i++)
		{
			temp_arr[i] = data_[i];
		}

		//I want NULLs in the new space, not "equal signs"
		//could be useful if you want to control default
		//character put into new space
		for (unsigned int i = cur_size_; i < new_size; i++)
		{
			temp_arr[i] = NULL;
		}

		//update sizes of array
		cur_size_ = new_size;
		max_size_ = new_size;

		//swapping temp_arr and data_ pointers
		temp_ptr = data_;
		data_ = temp_arr;
		temp_arr = temp_ptr;

		//get rid of temporary array
		delete[] temp_arr;
		temp_arr = nullptr;
	}

	//else if same, just return
	return;
}

//
// find (char)
//
template  <typename T>
int Array <T>::find (T value) const
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
int Array <T>::find (T val, size_t start) const
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
bool Array <T>::operator == (const Array <T> & rhs) const
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
bool Array <T>::operator != (const Array <T> & rhs) const
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
void Array <T>::fill (T value)
{
	//fill in array of the current size
	//with specified value
	for (unsigned int i = 0; i < cur_size_; i++)
	{
		data_[i] = value;
	}
}

//
// shrink
//
template <typename T>
void Array <T>::shrink(void)
{
	//If max size is same as current size, just return
	if (max_size_ == cur_size_)
	{
		return;
	}

	//temp array to hold original contents
	T * temp_arr;
	temp_arr = new T[cur_size_];
	//copy original values over into temp array
	for (unsigned int i = 0; i < cur_size_; i++)
	{
		temp_arr[i] = data_[i];
	}

	//get rid of old data_[] array
	delete[] data_;
	data_ = nullptr;

	//make a new array with the proper
	//(what will be) max size
	data_ = new T[cur_size_];

	//place new values into data_[]
	//preserving any original values in old array
	for (unsigned int i = 0; i < cur_size_; i++)
	{
		data_[i] = temp_arr[i];
	}

	//make max size the same as current size now
	max_size_ = cur_size_;
}

//
// reverse
//
template <typename T>
void Array <T>::reverse(void)
{
	//temp T for swapping elements around
	T temp_T;

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