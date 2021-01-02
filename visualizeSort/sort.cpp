#include <iostream>
#include <unordered_map>
#include <random>

#include "sort.h"

Sort::Sort()
    : _dataSize(0)
    , _count(0)
    , _p(0)
    , _q(0)
{

}

void Sort::initData()
{
    if (_dataSize <= 0) {
        std::cout << "error: init first" << std::endl;
        return;
    }

    // 시드값을 얻기 위한 생성
    std::random_device rd;
    // random_device 를 통해 난수 생성 엔진 초기화
    std::mt19937 gen(rd());
    // 균등 분포
    std::uniform_int_distribution<int> dis(1, _dataSize);

    std::unordered_map<int, bool> umap;
    _data.clear();
    _data.reserve(_dataSize);
    uint32_t val = 0;
    while (_data.size() < _dataSize) {
        val = dis(gen);
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
