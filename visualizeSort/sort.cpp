#include <iostream>
#include <unordered_map>

#if defined(USE_STDC_RANDOM)
#include <stdlib.h>
#include <time.h>
#endif

#include "sort.h"

Sort::Sort()
    : _dataSize(0)
    , _count(0)
    , _p(0)
    , _q(0)
#if defined(USE_STDCPP_RANDOM)
    , _gen(std::random_device()())
#endif
{
#if defined(USE_STDC_RANDOM)
    srand(time(NULL));
#endif
}

void Sort::initData()
{
    if (_dataSize <= 0) {
        std::cout << "error: init first" << std::endl;
        return;
    }

#if defined(USE_STDCPP_RANDOM)
    // 균등 분포
    std::uniform_int_distribution<uint32_t> dis(1, _dataSize);
#endif

    std::unordered_map<uint32_t, bool> umap;
    umap.clear();
    _data.clear();
    _data.reserve(_dataSize);
    uint32_t val = 0;
    while (_data.size() < _dataSize) {
#if defined(USE_STDCPP_RANDOM)
        val = dis(_gen);
#elif defined(USE_STDC_RANDOM)
        val = (rand()%_dataSize) + 1;
#endif
        if (umap[val]) {
            continue;
        }
        _data.push_back(val);
        umap[val] = true;
    }
}

void Sort::init(uint32_t dataSize)
{
    _count = 0;
    _p = 0;
    _q = 0;
    _dataSize = dataSize;

    initData();
}

bool Sort::swap(uint32_t p, uint32_t q)
{
    if (_data[p] <= _data[q]) {
        return false; // not need to swap
    }
    int32_t temp = _data[p];
    _data[p] = _data[q];
    _data[q] = temp;
    // swapped
    emit swapped();

    return true;
}

void Sort::toString()
{
    for (auto itr = _data.begin(); itr < _data.end(); itr++) {
        std::cout << *itr << " ";
    }
    std::cout << std::endl;
}
