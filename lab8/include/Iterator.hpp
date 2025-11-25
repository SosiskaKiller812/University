#pragma once

#include <iterator>

template<typename T>
class Ring;

template<typename T>
class RingIterator {
public:
    using iterator_category = std::bidirectional_iterator_tag;
    using value_type        = T;
    using difference_type   = std::ptrdiff_t;
    using pointer           = T*;
    using reference         = T&;

private:
    Ring<T>* m_ring;
    typename Ring<T>::Node* m_node;

public:
    RingIterator();
    RingIterator(Ring<T>* ring, typename Ring<T>::Node* node);

    reference operator*() const;
    pointer operator->() const;

    RingIterator& operator++();
    RingIterator operator++(int);

    RingIterator& operator--();
    RingIterator operator--(int);

    bool operator==(const RingIterator& other) const;
    bool operator!=(const RingIterator& other) const;
};

template<typename T>
RingIterator<T>::RingIterator()
    : m_ring(nullptr), m_node(nullptr) {}

template<typename T>
RingIterator<T>::RingIterator(Ring<T>* ring, typename Ring<T>::Node* node)
    : m_ring(ring), m_node(node) {}

template<typename T>
typename RingIterator<T>::reference RingIterator<T>::operator*() const {
    return m_node->value;
}

template<typename T>
typename RingIterator<T>::pointer RingIterator<T>::operator->() const {
    return &m_node->value;
}

template<typename T>
RingIterator<T>& RingIterator<T>::operator++() {
    if (!m_node) {
        return *this;
    }
    m_node = m_node->next;
    if (m_node == m_ring->head()) {
        m_node = nullptr;
    }
    return *this;
}

template<typename T>
RingIterator<T> RingIterator<T>::operator++(int) {
    RingIterator<T> tmp(*this);
    ++(*this);
    return tmp;
}

template<typename T>
RingIterator<T>& RingIterator<T>::operator--() {
    if (!m_ring) {
        return *this;
    }
    if (!m_node) {
        m_node = m_ring->head()->prev;
    } else {
        m_node = m_node->prev;
    }
    return *this;
}

template<typename T>
RingIterator<T> RingIterator<T>::operator--(int) {
    RingIterator<T> tmp(*this);
    --(*this);
    return tmp;
}

template<typename T>
bool RingIterator<T>::operator==(const RingIterator<T>& other) const {
    return m_ring == other.m_ring && m_node == other.m_node;
}

template<typename T>
bool RingIterator<T>::operator!=(const RingIterator<T>& other) const {
    return !(*this == other);
}

