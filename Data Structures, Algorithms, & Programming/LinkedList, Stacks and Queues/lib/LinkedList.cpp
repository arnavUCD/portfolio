#ifndef LINKED_LIST_CPP
#define LINKED_LIST_CPP

#include "LinkedList.hpp"

template <typename T>
LinkedList<T>::LinkedList() : _size(0), _head(nullptr), _tail(nullptr) {}

template <typename T>
LinkedList<T>::LinkedList(LinkedList<T> &&other) : _size(other._size),
                                                   _head(other._head),
                                                   _tail(other._tail)
{
    other._size = 0;
    other._head = nullptr;
    other._tail = nullptr;
}

// TODO: Implement all other methods defined in LinkedList.hpp here

// Initialize size and pointers
template <typename T>
LinkedList<T>::LinkedList(const std::vector<T> &items) : _size(0), _head(nullptr), _tail(nullptr)
{
    for (const T &item : items) // Iterate over each item in the input vector and append it to the list
    {
        append(item); // Add the current item to the end of the list
    }
}

// Function to return the size of the linked list
// The function is marked as const since it does not modify the object
template <typename T>
size_t LinkedList<T>::size() const
{
    return _size;
}

// Function to return the head node of the linked list
// The function is marked as const since it does not modify the object
template <typename T>
LinkedListNode<T> *LinkedList<T>::head() const
{
    return _head;
}


// Function to return the tail (last) node of the linked list
// The function is marked as const since it does not modify the object
template <typename T>
LinkedListNode<T> *LinkedList<T>::tail() const
{
    return _tail;
}


// Function to iterate through the linked list to find a node containing the specified value
// The function is marked as const since it does not modify the list
// Each node has a 'value' that stores the data and a '_next' pointer to the next node
template <typename T>
LinkedListNode<T> *LinkedList<T>::find(T value) const
{
    LinkedListNode<T> *currentNode = _head;
    while (currentNode != nullptr)
    {
        if (currentNode->value == value) // Check if the current node holds the desired value
        {
            return currentNode;
        }
        currentNode = currentNode->_next;
    }
    return nullptr; // Return nullptr if the value is not found in the list
}


// Function to prepend a node to the beginning of the linked list
// This function adds a new node containing the given value at the head of the list
// If the list is empty, the new node will be both the head and the tail
template <typename T>
LinkedListNode<T> *LinkedList<T>::prepend(T value)
{
    LinkedListNode<T> *nNode = new LinkedListNode<T>(value, _head);
    if (_head == nullptr)
    {
        _head = _tail = nNode; // Update the head to the new node
    }
    else
    {
        _head = nNode;
    }
    _size++; // Increment the size of the list
    return nNode;
}

// Function to append a node to the end of the linked list
// This function adds a new node containing the given value at the tail of the list
template <typename T>
LinkedListNode<T> *LinkedList<T>::append(T value)
{
    LinkedListNode<T> *nNode = new LinkedListNode<T>(value); // If the list is empty, set both head and tail to the new node
    if (_tail == nullptr)
    {
        _head = nNode;
    }
    else
    {
        _tail->_next = nNode; // Set the _next pointer of the current tail to the new node
    }
    _tail = nNode; // Update the tail to the new node
    _size++; // Increment the size of the list
    return nNode;
}


// Function to insert a new element after a specified node in the linked list
// If the specified node is nullptr, the new node will be prepended to the list
template <typename T>
LinkedListNode<T> *LinkedList<T>::insertAfter(LinkedListNode<T> *node, T value)
{
    if (node == nullptr) // If the specified node is nullptr, prepend the value to the list
    {
        return prepend(value);
    }
    LinkedListNode<T> *nNode = new LinkedListNode<T>(value, node->_next);
    node->_next = nNode; // Update the specified node's _next pointer to the new node
    if (node == _tail)
    {
        _tail = nNode;
    }
    _size++;
    return nNode;
}

// Function to remove the head (first) node of the linked list
// Returns the value of the removed node as an optional, or std::nullopt if the list is empty
template <typename T>
std::optional<T> LinkedList<T>::removeHead()
{
    if (_head == nullptr)
    {
        return std::nullopt;
    }
    LinkedListNode<T> *oldHead = _head; // Save the current head to be deleted
    _head = _head->_next;
    if (_head == nullptr) // If the list becomes empty after removal, reset the tail pointer as well
    {
        _tail = nullptr;
    }
    _size--;
    T reValue = oldHead->value;
    delete oldHead;
    return reValue;
}


/// Function to remove the first occurrence of the specified value in the linked list
// Returns true if the value is found and removed, false if the value is not found
template <typename T>
bool LinkedList<T>::remove(T value)
{
    if (_head == nullptr)
    {
        return false;
    }

    if (_head->value == value)
    {
        removeHead();
        return true;
    }

    LinkedListNode<T> *currentNode = _head;
    while (currentNode->_next != nullptr)
    {
        if (currentNode->_next->value == value)
        {
            LinkedListNode<T> *nodeDel = currentNode->_next;
            currentNode->_next = currentNode->_next->_next;
            if (nodeDel == _tail)
            {
                _tail = currentNode;
            }
            delete nodeDel;
            _size--;
            return true;
        }
        currentNode = currentNode->_next;
    }
    return false;
}

// Function to remove all elements from the linked list
// Iterates through the list and removes each node by calling removeHead()
template <typename T>
void LinkedList<T>::clear()
{
    while (_head != nullptr)
    {
        removeHead();
    }
}

// Destructor to automatically clear the list when the LinkedList object is destroyed
// This ensures proper memory cleanup when the object goes out of scope
template <typename T>
LinkedList<T>::~LinkedList()
{
    clear();
}

#endif