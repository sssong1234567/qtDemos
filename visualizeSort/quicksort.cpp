#include "quicksort.h"

QuickSort::QuickSort()
{

}

void QuickSort::init(uint32_t dataSize)
{
    Sort::init(dataSize);

    _left.clear();
    _right.clear();
}

// from wikipedia c++ version
// https://ko.wikipedia.org/wiki/%ED%80%B5_%EC%A0%95%EB%A0%AC
bool QuickSort::sort()
{
    StackItem item(0, _data.size() - 1);

    if (_left.size() != 0) {
        item = _left.back();
        _left.pop_back();
    }
    else if (_right.size() != 0) {
        item = _right.back();
        _right.pop_back();
    }

    quickSort(item.low, item.high);

    return true;
}

bool QuickSort::quickSort(int32_t low, int32_t high)
{
    if (low >= high)
        return false;

    int32_t i = low-1;
    int32_t j = low;
    int32_t pivot = _data[high];

    for (; j < high; j++) {
        if (_data[j] < pivot) {
            swap(++i, j);
        }
    }
    swap(++i, high);

    _left.push_back(StackItem(low, i-1));
    _right.push_back(StackItem(i+1, high));
    return true;
}
