#include <atomic>
#include "ArrayLinkIterator.h"

template<typename T>
struct Node
{
    T value;
    std::atomic<int64_t> next;
};


template<typename T>
class ArrayLink
{
public:
    using Iterator = ArrayLinkIterator<Node<T>>;

    ArrayLink(){}
    ArrayLink(const ArrayLink& other){}
    virtual ~ArrayLink(){}

    void push_back(const T& value) {}
    void insert(int64_t index, const T& value) {}
    void erase(const T& value) {}

    Iterator begin() {}
    Iterator end() {}

private:
    std::atomic<int64_t> first;
    Node<T>* data;
};
