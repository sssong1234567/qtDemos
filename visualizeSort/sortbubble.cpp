#include <iostream>
#include "sortbubble.h"

SortBubble::SortBubble()
    : Sort()
{
}

void SortBubble::init(uint32_t dataSize)
{
    Sort::init(dataSize);

    _q = dataSize - 1;
}

bool SortBubble::sort()
{
    do {
        if (swap(_p, _p+1)) {
            swapped();
            return true;
        }
    } while(move());

    return false;
}

bool SortBubble::move()
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
bool SortBubble::swapped()
{
    _count++;
    return move(); // end of sort
}
