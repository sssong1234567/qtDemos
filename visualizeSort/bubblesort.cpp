#include <iostream>
#include "bubblesort.h"

BubbleSort::BubbleSort()
    : Sort()
{
}

void BubbleSort::init(uint32_t dataSize)
{
    Sort::init(dataSize);

    _q = dataSize - 1;
}

bool BubbleSort::sort()
{
    do {
        if (swap(_p, _p+1)) {
            swapped();
            return true;
        }
    } while(move());

    return false;
}

bool BubbleSort::move()
{
    if (_p < _q - 1) {
        _p++;
        return true;
    }
    if (_q >= 2) {
        _q--;
        _p = 0;
        return true;
    }
    return false;
}
bool BubbleSort::swapped()
{
    _count++;
    return move(); // end of sort
}
