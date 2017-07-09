// -*- C++ -*-
// $Id: Queue.cpp ls809@#^fhj23jko4oh0ah#$jdkflje jwignot ;)
//
// Honor Pledge: Jason Wignot
//
// I pledge that I have neither given nor received any help on
// this assignment.

#include "Queue.h"
#include <stdexcept>         // for std::out_of_bounds exception

#define Q_SIZE_MAX 4294967295

//
// Constructor
//
template <typename T>
Queue <T>::Queue(void) : 
q_head_(0),
q_tail_(0),
q_size_(0),
queue_(0)
{
	
}

//
// Copy Constructor
//
template <typename T>
Queue <T>::Queue(const Queue <T> & queue) :
q_head_(queue.q_head_),
q_tail_(queue.q_tail_),
q_size_(queue.q_size_),
queue_(queue.queue_)
{
	//initializing the array
	for (unsigned int i = 0; i < q_size_; i++)
	{
		queue_[i] = queue.queue_[i];
	}
}

//
// Destructor
//
template <typename T>
Queue <T>::~Queue(void)
{
	// Not needed but clearing
	// the queue out anyway before deletion.
	Queue<T>::clear();
}

//
// Assignment Operator
//
//const Array <T> & Array <T>::operator = (const Array <T> & rhs)
template <typename T>
const Queue <T> & Queue <T>::operator = (const Queue <T> & rhs)
{
	// Check for self assignment first
	if (this == &rhs)
	{
		return *this;
	}

	// Check if same, if so, return
	if (queue_ == rhs.queue_)
	{
		return *this;
	}

	// Resize the array to make sure it's the same size
	queue_.resize(rhs.size());

	// Copy one side to the other
	for (unsigned int i = 0; i < queue_.size(); i++)
	{
		queue_[i] = rhs.queue_[i];
	}
	return *this;
}

//
// front
//
template <typename T>
T Queue <T>::front(void)
{
	// Get value at head of queue
	return queue_.get(q_head_);
}

//
// enqueue
//
template <typename T>
void Queue <T>::enqueue(T element)
{
	// Only would happen in heavy duty usage...
	// but I'm checking for too large a queue.
	// 4,294,967,295 seems large enough for now.
	if (q_size_ >= Q_SIZE_MAX || queue_.size() >= Q_SIZE_MAX)
	{
		try
		{
			throw std::out_of_range("Queue is its max size");
		}
		catch (std::out_of_range &e)
		{
			std::cout << "Queue is its max size" << std::endl;
		}
	}

	// Resize the queue by 1+ to
	// make space for the element
	queue_.resize(1 + q_size_);

	// Actually "enqueue" the element 
	// with the Array::set() method
	queue_.set(q_size_, element);

	// Update indexes
	q_tail_++;
	q_size_++;
}

//
// dequeue
//
template <typename T>
T Queue<T>::dequeue(void)
{
	if (is_empty())
	{
		try
		{
			throw std::out_of_range("Queue is empty");
		}
		catch (std::out_of_range &e)
		{
			std::cout << "Queue is empty" << std::endl;
		}
	}

	// Get object at head of queue (head is always 0)
	// before I wipe away its memory space.
	T dequeued_object = queue_.get(q_head_);

	// i MUST BE initialized to 1, to avoid going out of bounds.
	// I'm shifting all the values backwards 1, after getting
	// return value for dequeue
	for (unsigned int i = 1; i < q_size_; i++)
	{
		queue_[i - 1] = queue_[i];
	}

	// Move tail back one before resize and size decreases
	q_tail_--;
	q_size_--;

	// Resize the queue with the updated
	// smaller size now
	queue_.resize(q_size_);

	// Return object at previous head of queue
	return dequeued_object;
}

//
// clear
//
template <typename T>
void Queue <T>::clear(void)
{
	// Not most performance-oriented way to do things,
	// but reduces some security risks by cleansing


	// Set size back to zero, and resize
	// after cleansing memory
	q_tail_ = 0;
	q_size_ = 0;
	queue_.resize(q_size_);
}

//
// size
//
template <typename T>
size_t Queue <T>::size(void) const
{
	// Get access to Array<T> cur_size_ variable
	// This is used for copy constructor, otherwise
	// client can use "q_size_" for size of queue.
	return queue_.size();
}

//
// is_empty
//
template <typename T>
bool Queue <T>::is_empty(void) const
{
	//only need below line for functionality
	//if head = tail, then size is zero
	return (q_head_ == q_tail_);
}