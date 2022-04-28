
template<typename N>
struct ArrayLinkIterator
{
    using iterator_category = std::forward_iterator_tag;
    using difference_type   = std::ptrdiff_t;
    using value_type        = N;
    using pointer           = N*;
    using reference         = N&;

    ArrayLinkIterator(pointer ptr) : m_ptr(ptr) 
    {
        array = (m_ptr == nullptr) ? m_ptr: &m_ptr[0]; 
    }
    ArrayLinkIterator(const ArrayLinkIterator& other) : m_ptr(other.mptr) {}

    reference operator*() const {return (*m_ptr).value; }
    pointer operator->() const {return &(m_ptr->value); }

    ArrayLinkIterator& operator++() {
        m_ptr = (m_ptr->next != -1) ? array + m_ptr->next : nullptr;
        return *this;
    }
private:
    pointer m_ptr;
    N* array;
};
