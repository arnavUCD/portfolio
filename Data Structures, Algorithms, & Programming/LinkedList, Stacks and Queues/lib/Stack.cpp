#ifndef STACK_CPP
#define STACK_CPP

#include "Stack.hpp"

template <typename T>
Stack<T>::Stack() {}

// TODO: Implement all other methods defined in Stack.hpp here

// Constructor to initialize the stack with a vector of items
// Each item in the vector is pushed onto the stack in the order it appears
// _llist is assumed to be an instance of LinkedList<T> that the stack uses internally
template <typename T>
Stack<T>::Stack(const std::vector<T> &items) : _llist()
{
    for (const T &item : items)
    {
        push(item);
    }
}

// Function to return the size of the stack (i.e., the number of elements in the stack)
// _llist is assumed to be a LinkedList<T> that stores the elements of the stack
// The size() function of LinkedList<T> returns the number of nodes in the list
template <typename T>
size_t Stack<T>::size() const
{
    return _llist.size();
}


// Function to return the top element of the stack
// Returns an optional, with std::nullopt if the stack is empty
// _llist is assumed to be a LinkedList<T>, and tail() returns the last (top) element of the stack
template <typename T>
std::optional<T> Stack<T>::top() const
{
    if (_llist.size() == 0)
    {
        return std::nullopt;
    }
    return _llist.tail()->value;
}


// Function to add (push) an element onto the stack
// The element is added to the top of the stack by prepending it to the linked list (_llist)
// _llist is assumed to be a LinkedList<T>, and prepend() adds the element to the front
template <typename T>
void Stack<T>::push(T value)
{
    _llist.prepend(value);
}


// Function to remove (pop) the top element from the stack and return its value
// Uses the removeHead() function from the underlying linked list (_llist) to remove the first element
// Returns an optional containing the removed value, or std::nullopt if the stack is empty
template <typename T>
std::optional<T> Stack<T>::pop()
{
    return _llist.removeHead();
}
#endif