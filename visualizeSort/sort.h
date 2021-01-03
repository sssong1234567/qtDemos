#ifndef SORT_H
#define SORT_H

#include <cstdint>
#include <vector>
#include <QObject>

// mingw 에서는 random_device가 정상적으로 구현되지 않아
// pseudo random을 반환하여 seed값이 같으므로
// 프로그램 실행시마다 같은 랜덤값이 반복된다.
#define USE_STDC_RANDOM

#if defined(USE_STDCPP_RANDOM)
#include <random>
#endif

class Sort : public QObject
{
    Q_OBJECT

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
    virtual bool sort() = 0;
    virtual void toString();
    std::vector<int32_t>& data() {return _data; }
    uint32_t count() { return _count; }

#if defined(USE_STD_RANDOM)
    std::mt19937 _gen;
#endif

protected:
    bool swap(uint32_t p, uint32_t q);

signals:
    void swapped();
};

#endif // SORT_H
