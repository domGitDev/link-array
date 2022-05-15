#include <atomic>
#include <unordered_map>
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

    ArrayLink(size_t size=0) : _size(size), _capacity(10)
    {
        data = (Node<T>*)malloc(_capacity * sizeof(Node<T>));
        assert(data != nullptr);
    }

    ArrayLink(const ArrayLink& other) = delete;

    virtual ~ArrayLink()
    {
        if(data != nullptr)
            free(data);
        data = nullptr;
    }

    void resize(int64_t size)
    {
        _size = size;
        _capacity = size;
        data = (Node<T>*)realloc(data, _size * sizeof(Node<T>));
        assert(data != nullptr);
    }

    void push_ordered(const T& value) 
    {
        /** find ordered insertion index
         * copy value at size - 1
         * mapped insertion index to last element in array
         * set prev next to ordered position
         * 
         * case size == 0, insert at begin and update first
         * case insertion index >= size update prev next and set next =-1
         * case insertion index middle, set prev next to new node and curr next to next node
        **/
        
    }

    void insert(int64_t i, const T& value) 
    {
        assert (i <= _size)

        int64_t last = (_size > 0) ? _size - 1: 0;
        data[last].value = value;
        data[last].next = -1;
        if(_size > 1)
        {
            /** reordering **/
            const int64_t& j = (indices.count(i) > 0) ? indices.at(i) : last;
            int64_t next = data[j-1].next;
            data[j-1].next = last;
            data[last].next = next;
        }

        indices.emplace(i,last);
        ++_size;
    }

    void erase(const T& value) {}

    /** using mapped index to data to access in order **/
    T& at(int64_t i) 
    {
        const int64_t& j = indices.at(i);
        return &(data[j].value);
    }

    Iterator begin() {}
    Iterator end() {}

private:
    size_t _size;
    size_t _capacity;
    std::atomic<int64_t> first;
    std::unordered_map<int64_t, int64_t> indices;
    Node<T>* data;
};
