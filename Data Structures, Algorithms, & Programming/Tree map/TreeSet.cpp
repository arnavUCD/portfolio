/* Name: Arnav Sharma
 * 11/1/2024
 * SID:921870432 */

#ifndef TREE_SET_CPP
#define TREE_SET_CPP

#include "TreeSet.hpp"
#include <stack>
#include <queue>
#include <iostream>

template <typename T>
TreeSet<T>::TreeSet() : _root(nullptr), _size(0)
{
    _comparator = [](T left, T right)
    {
        if (left < right)
        {
            return -1;
        }
        else if (left > right)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    };
}

// TODO: Implement all methods defined in TreeSet.hpp here

// Add each item in the vector to the TreeSet
template <typename T>
TreeSet<T>::TreeSet(const std::vector<T> &items) : _root(nullptr),
                                                   _comparator([](const T &left, const T &right)
                                                               { return left < right ? -1 : (left > right ? 1 : 0); }),
                                                   _size(0)
{
    for (const T &item : items)
    {
        add(item);
    }
}

// Constructor with a custom comparator
template <typename T>
TreeSet<T>::TreeSet(std::function<int(T, T)> comparator) : _root(nullptr), _comparator(comparator), _size(0) {}
// Constructor with both items and a custom comparator
template <typename T>
TreeSet<T>::TreeSet(const std::vector<T> &items, std::function<int(T, T)> comparator) : _root(nullptr), _comparator(comparator), _size(0)
{
    // Add each item in the vector to the TreeSet
    for (const T &item : items)
    {
        add(item);
    }
}

// Left rotation function for rebalancing the tree
template <typename T>
void TreeSet<T>::rotate_left(BinaryTreeNode<T> *x)
{
    BinaryTreeNode<T> *y = x->_right; // y is the right child of x
    x->_right = y->_left; // Set x's right child to y's left child
    if (y->_left != nullptr)
    {
        y->_left->_parent = x;
    }
    y->_parent = x->_parent;
    if (x->_parent == nullptr)
    {
        _root = y;
    }
    else if (x == x->_parent->_left)
    {
        x->_parent->_left = y;
    }
    else
    {
        x->_parent->_right = y;
    }
    y->_left = x;
    x->_parent = y;
}

// Right rotation function for rebalancing the tree
template <typename T>
void TreeSet<T>::rotate_right(BinaryTreeNode<T> *y)
{
    BinaryTreeNode<T> *x = y->_left; // x is the left child of y
    y->_left = x->_right; // Set y's left child to x's right child
    if (x->_right != nullptr)
    {
        x->_right->_parent = y;
    }
    x->_parent = y->_parent; // Set x's parent to y's parent
    if (y->_parent == nullptr)
    {
        _root = x;
    }
    else if (y == y->_parent->_left)
    {
        y->_parent->_left = x;
    }
    else
    {
        y->_parent->_right = x; // Set x as the right child of y's parent
    }
    x->_right = y; // Set y as x's right child
    y->_parent = x; // Set x as y's parent
}

// Fixes Red-Black Tree violations after insertion
template <typename T>
void TreeSet<T>::fix_violation(BinaryTreeNode<T> *z)
{
    // Continue until reaching the root or the parent node is black
    while (z != _root && z->_parent->_color == Red)
    {
        if (z->_parent == z->_parent->_parent->_left)
        {
            // If the parent is the left child
            BinaryTreeNode<T> *y = z->_parent->_parent->_right;
            if (y != nullptr && y->_color == Red)
            {
                z->_parent->_color = Black;
                y->_color = Black;
                z->_parent->_parent->_color = Red;
                z = z->_parent->_parent;
            }
            else
            {
                if (z == z->_parent->_right) // Right child case
                {
                    z = z->_parent;
                    rotate_left(z);
                }
                z->_parent->_color = Black;
                z->_parent->_parent->_color = Red;
                rotate_right(z->_parent->_parent);
            }
        }
        else
        {
            BinaryTreeNode<T> *y = z->_parent->_parent->_left;
            if (y != nullptr && y->_color == Red)
            {
                z->_parent->_color = Black;
                y->_color = Black;
                z->_parent->_parent->_color = Red;
                z = z->_parent->_parent;
            }
            else
            {
                if (z == z->_parent->_left)
                {
                    z = z->_parent;
                    rotate_right(z);
                }
                z->_parent->_color = Black;
                z->_parent->_parent->_color = Red;
                rotate_left(z->_parent->_parent);
            }
        }
    }
    _root->_color = Black;
}

// Returns the size of the TreeSet
template <typename T>
size_t TreeSet<T>::size() const
{
    return _size;
}

// Adds a value to the TreeSet
template <typename T>
void TreeSet<T>::add(T value)
{
    BinaryTreeNode<T> *newnode = new BinaryTreeNode<T>(value);
    newnode->_color = Red;

    if (is_empty())
    {
        newnode->_color = Black;
        _root = newnode;
    }
    else
    {
        // prev points to parent of curr
        BinaryTreeNode<T> *y = nullptr;
        BinaryTreeNode<T> *x = _root;
        while (x != nullptr)
        {
            y = x;
            if (_comparator(value, x->value) > 0)
            {
                x = x->_right;
            }
            else if (_comparator(value, x->value) < 0)
            {
                x = x->_left;
            }
            else
            {

                x->value = value;
                delete newnode;
                return;
            }
        }

        newnode->_parent = y;
        if (_comparator(value, y->value) > 0)
        {
            y->_right = newnode;
        }
        else
        {
            y->_left = newnode;
        }
    }
    fix_violation(newnode);
    ++_size;
}
template <typename T>
bool TreeSet<T>::contains(T value) const
{
    // Create curr pointer
    BinaryTreeNode<T> *curr = _root;
    // loop through, if value is bigger, go right, if its smaller go left
    while (curr != nullptr)
    {
        if (_comparator(value, curr->value) > 0)
        {
            curr = curr->_right;
        }
        else if (_comparator(value, curr->value) < 0)
        {
            curr = curr->_left;
        }
        else
        {
            return true;
        }
    }
    return false;
}

template <typename T>
bool TreeSet<T>::is_empty() const
{
    if ((_root == nullptr) || (_size == 0))
    {
        return true;
    }
    return false;
}

template <typename T>
std::optional<T> TreeSet<T>::min() const
{
    BinaryTreeNode<T> *curr = _root;

    if (_root == nullptr)
    {
        return std::nullopt;
    }

    while (curr->_left != nullptr)
    {
        curr = curr->_left;
    }
    return std::make_optional(curr->value);
}

template <typename T>
std::optional<T> TreeSet<T>::max() const
{
    BinaryTreeNode<T> *curr = _root;

    if (_root == nullptr)
    {
        return std::nullopt;
    }

    while (curr->_right != nullptr)
    {
        curr = curr->_right;
    }
    return std::make_optional(curr->value);
}

// non recursive approach
template <typename T>
std::vector<T> TreeSet<T>::to_vector() const
{
    std::vector<T> container;
    if (_size == 0)
    {
        return container;
    }
    std::stack<BinaryTreeNode<T> *> stack;
    BinaryTreeNode<T> *curr = _root;
    while (curr != nullptr || !stack.empty())
    {
        while (curr != nullptr)
        {
            stack.push(curr);
            curr = curr->_left;
        }
        curr = stack.top();
        stack.pop();
        container.push_back(curr->value);
        curr = curr->_right;
    }

    return container;
}

template <typename T>
std::optional<T> TreeSet<T>::get(T value) const
{
    BinaryTreeNode<T> *curr = _root;
    while (curr != nullptr)
    {
        if (_comparator(value, curr->value) < 0)
        {
            curr = curr->_left;
        }
        else if (_comparator(value, curr->value) > 0)
        {
            curr = curr->_right;
        }
        else
        {
            return curr->value;
        }
    }
    return std::nullopt;
}

template <typename T>
TreeSet<T> TreeSet<T>::operator+(const TreeSet<T> &other)
{
    TreeSet<T> total(_comparator);
    std::vector<T> temptotal;
    std::vector<T> s1 = to_vector();
    std::vector<T> s2 = other.to_vector();
    for (int i = 0; i < s1.size(); i++)
    {
        temptotal.push_back(s1[i]);
    }
    for (int i = 0; i < s2.size(); i++)
    {
        temptotal.push_back(s2[i]);
    }
    for (int i = 0; i < temptotal.size(); i++)
    {
        total.add(temptotal[i]);
    }
    return total;
}

template <typename T>
TreeSet<T> &TreeSet<T>::operator+=(const TreeSet<T> &other)
{
    std::vector first = this->to_vector();
    std::vector second = other.to_vector();

    for (int i = 0; i < second.size(); i++)
    {
        this->add(second[i]);
    }

    return *this;
}

template <typename T>
TreeSet<T> TreeSet<T>::operator&(const TreeSet &other)
{
    TreeSet<T> total(_comparator);
    std::vector first = to_vector();
    std::vector second = other.to_vector();
    for (int i = 0, j = 0; i < first.size() && j < second.size();)
    {
        if (first[i] == second[j])
        {
            total.add(first[i]);
            ++i;
            ++j;
        }
        else if (first[i] < second[j])
        {
            ++i;
        }
        else
        {
            ++j;
        }
    }
    return total;
}

// Operator== to check equality of two TreeSets
template <typename T>
bool TreeSet<T>::operator==(const TreeSet &other) const
{
    std::vector first = to_vector();
    std::vector second = other.to_vector();
    std::sort(first.begin(), first.end());
    std::sort(second.begin(), second.end());
    if (first.size() != second.size())
    {
        return false;
    }
    int count;
    for (int i = 0; i < first.size(); i++)
    {
        if (first[i] != second[i])
        {
            return false;
        }
    }
    return true;
}

template <typename T>
bool TreeSet<T>::operator!=(const TreeSet &other) const
{
    TreeSet<T> first(_comparator);
    std::vector temp = to_vector();
    for (int i = 0; i < _size; i++)
    {
        first.add(temp[i]);
    }
    if (first == other)
    {
        return false;
    }
    else
    {
        return true;
    }
}
template <typename T>
void TreeSet<T>::clear()
{
    if (_size == 0)
    {
        return;
    }
    if (_root == nullptr)
    {
        return;
    }

    // Function uses a queue to keep track of the BFS traversal, and deleting each node
    std::queue<BinaryTreeNode<T> *> queue;
    queue.push(_root);
    while (!queue.empty())
    {
        // current pointer points to root
        BinaryTreeNode<T> *curr = queue.front();
        queue.pop();
        if (curr->_left != nullptr)
        {
            queue.push(curr->_left);
        }
        if (curr->_right != nullptr)
        {
            queue.push(curr->_right);
        }
        delete curr;
        --_size;
    }
    _root = nullptr;
}

// Destructor to clear the TreeSet on deletion
template <typename T>
TreeSet<T>::~TreeSet()
{
    clear();
}

#endif