#ifndef SORT_H
#define SORT_H

#include <cstdint>
#include <vector>
#include <QObject>

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

protected:
    bool swap(uint32_t p, uint32_t q);

signals:
    void swapped();
};

#endif // SORT_H
