#ifndef BUBBLESORT_H
#define BUBBLESORT_H

#include "sort.h"

class BubbleSort : public Sort
{
public:
    BubbleSort();

    virtual bool sort();
    bool bubbleSort();

protected:
    virtual void init(uint32_t dataSize);

private:
    bool move();
    bool swapped();
};

#endif // BUBBLESORT_H
