#ifndef SORT_H
#define SORT_H

#include <cstdint>
#include <vector>

class Sort
{
public:
    Sort();
    ~Sort() {};

private:
    void initData();

protected:
    uint32_t _dataSize;
    std::vector<int32_t> _data;
    uint32_t _count;
    uint32_t _p, _q;

public:
    virtual void init(uint32_t dataSize);
    virtual uint32_t sort() = 0;
    virtual void toString();
    std::vector<int32_t>& data() {return _data; }

protected:
    virtual bool swap(uint32_t p, uint32_t q);
};

#endif // SORT_H
