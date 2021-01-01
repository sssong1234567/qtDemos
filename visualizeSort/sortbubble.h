#ifndef SORTBUBBLE_H
#define SORTBUBBLE_H

#include "sort.h"

class SortBubble : public Sort
{
public:
    SortBubble();

    virtual uint32_t sort();

protected:
    virtual void init(uint32_t dataSize);

private:
    bool move();
    bool swapped();
};

#endif // SORTBUBBLE_H