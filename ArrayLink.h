#include "ArrayLinkIterator.h"

template<typename T>
struct Node
{
    T value;
    int64_t next;
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
    void push_ordered(const T& value) {}
    void erase(const T& value) {}

    Iterator begin() {}
    Iterator end() {}

private:
    int64_t first;
    Node<T>* data;
};
