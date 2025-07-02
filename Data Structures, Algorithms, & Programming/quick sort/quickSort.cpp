// Name: Arnav Sharma

#ifndef QSORT_CPP
#define QSORT_CPP

#include <ctime>
#include <cstdlib>
#include "qsort.hpp"


// A partitioner function which rearranges the elements based on the pivot
template <typename RandomAccessIter, typename Comparator>
RandomAccessIter partitionerFn(RandomAccessIter first, RandomAccessIter last, Comparator comparator) {
    
    if (first != last) {
        int pivIndex = std::rand() % std::distance(first,last);
        RandomAccessIter random_pivot= first + pivIndex;
        std::swap(*random_pivot,*(last - 1)); //move random pivot to the end
    }

    RandomAccessIter pivot= last - 1;
    RandomAccessIter pivPos= first - 1; //pointer for smaller element

    // Divide range into two parts based on logic
    for (RandomAccessIter current= first;current <= last - 1; ++current) {
        //comparing
        if (comparator(*current,*pivot)) {
            ++i;
            std::swap(*pivPos,*current); //smaller to left
        }
    }

    
    std::swap(*(pivPos + 1),*(last - 1));
    return pivPos + 1; //returning the final
}

template <typename RandomAccessIter, typename Comparator>
void quick_sort(RandomAccessIter first, RandomAccessIter last, Comparator comparator) {
    
    if (first < last) {
        RandomAccessIter pivot = partitioner(first,last,comparator);
        //sorting the elements
        quick_sort(first,pivot,comparator);
        quick_sort(pivot + 1,last,comparator);
    }
}

#endif