#ifndef QUEUE_CPP
#define QUEUE_CPP

#include "Queue.hpp"

template <typename T>
Queue<T>::Queue(LinkedList<T> &&llist) : _llist(std::move(llist)) {}

template <typename T>
Queue<T>::Queue() : Queue(LinkedList<T>()) {}

// TODO: Implement all other methods defined in Queue.hpp here

// Constructor to initialize the queue with a vector of items
// _llist is assumed to be a LinkedList<T> that stores the queue's elements
// The LinkedList<T> constructor accepts a vector and initializes the queue with the elements
template <typename T>
Queue<T>::Queue(const std::vector<T> &items) : _llist(items) {}

// Function to return the size of the queue (i.e., the number of elements in the queue)
// _llist is assumed to be a LinkedList<T> that stores the elements of the queue
// The size() function of LinkedList<T> returns the number of nodes in the list
template <typename T>
size_t Queue<T>::size() const
{
    return _llist.size();
}

// Function to add (enqueue) an element to the queue
// The element is added to the end of the queue (Last-In, Last-Out - LILO) by appending it to the linked list (_llist)
// _llist is assumed to be a LinkedList<T>, and append() adds the element to the end
template <typename T>
void Queue<T>::enqueue(T value)
{
    _llist.append(value);
}

// Function to remove (dequeue) and return the oldest element from the queue (LILO behavior)
// Uses the removeHead() function from the underlying linked list (_llist) to remove the first element
// Returns an optional containing the removed value, or std::nullopt if the queue is empty
template <typename T>
std::optional<T> Queue<T>::dequeue()
{
    return _llist.removeHead();
}

#endif