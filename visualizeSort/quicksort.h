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

public:
    virtual void init(uint32_t dataSize);
    virtual bool sort();
    bool quickSort(int32_t low, int32_t high);
};

#endif // QUICKSORT_H
