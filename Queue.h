
#ifndef _QUEUE_H
#define _QUEUE_H

#include <cstring>          // for size_t definition
#include "Array.h"

/**
* @class Queue
*
* Implementation of a queue (an ADT that contains a
* list of elements such that the list has first-in, 
* first-out (FIFO) semantics, i.e., elements are 
* inserted into the end of the list and removed
* from the front of the list).
*/
template <typename T>
class Queue
{
public:
	/// Type definition of the element type
	typedef T type;

	/// Default constructor
	Queue(void);

	/**
	* Copy constructor
	*
	* @param[in]     queue         The source queue.
	*/
	Queue(const Queue <T> & queue);

	/// Destructor
	~Queue(void);

	/**
	* Assignment Operator
	*
	* @param[in]       rhs      Right-hand side of equal sign
	* @return          Reference to self
	*/
	const Queue & operator = (const Queue <T> & rhs);

	/**
	* front
	*
	* Returns the value at the front of queue
	* without dequeuing it
	* @return		Element of Type T
	*/
	T front(void);

	/**
	* enqueue
	*
	* Adds the element to the end of the list
	* @param[in]     element         Element to be added to the end of the list
	*/
	void enqueue(T element);

	/**
	* dequeue
	* 
	* Removes the element at the front of the list. If there are not elements in the
	* queue, this method throws empty_exception, similar to the stack.
	*
	* @return          element at front of the queue
	* @exception       std::empty_exception   No elements in the queue
	*/
	T dequeue(void);

	/**
	* is_empty
	*
	* @retval          true            Head index is equal to the tail index
	* @retval          false           Heas index is not equal to the tail index
	*/
	bool is_empty(void) const;

	/**
	* size
	*
	* Returns the number of elements in the queue.
	*
	* @param[in]     element         Element to be added to the end of the list
	*/
	size_t size(void) const;
	
	/**
	* clear
	* 
	* Removes all elements in the queue.
	*
	*/
	void clear(void);


private:
	/// Get access to private Array variables
	Array<T> queue_;

	/// First element in queue
	size_t q_head_;

	/// Last element in queue
	size_t q_tail_;

	/// Size of queue
	size_t q_size_;
};

#include "Queue.inl"
#include "Queue.cpp"

#endif // !defined _QUEUE_