#ifndef QUICKSORT_H
#define QUICKSORT_H

#include "sort.h"

typedef struct _StackItem {
    int32_t low;
    int32_t high;
    _StackItem(int32_t l, int32_t h) { low = l; high = h; };
} StackItem;

class QuickSort : public Sort
{
public:
    QuickSort();

private:
    std::vector<StackItem> _left;
    std::vector<StackItem> _right;

    bool swapped();
    bool quickSort(int32_t low, int32_t high);

public:
    virtual void init(uint32_t dataSize);
    virtual bool sort();
};

#endif // QUICKSORT_H
