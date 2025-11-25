#pragma once

#include <cstddef>

template<typename T>
class RingIterator;

template<typename T>
class Ring {
public:
    struct Node {
        T value;
        Node* next;
        Node* prev;

        explicit Node(const T& v)
            : value(v), next(nullptr), prev(nullptr) {}
    };

private:
    Node* m_head;
    std::size_t m_size;

public:
    using iterator = RingIterator<T>;

    Ring();
    ~Ring();

    Ring(const Ring&) = delete;
    Ring& operator=(const Ring&) = delete;

    bool empty() const;
    std::size_t size() const;

    void push_back(const T& value);
    void clear();

    iterator begin();
    iterator end();

    iterator begin() const;
    iterator end() const;

    Node* head() { return m_head; }
    const Node* head() const { return m_head; }
};

template<typename T>
Ring<T>::Ring()
    : m_head(nullptr), m_size(0) {}

template<typename T>
Ring<T>::~Ring() {
    clear();
}

template<typename T>
bool Ring<T>::empty() const {
    return m_size == 0;
}

template<typename T>
std::size_t Ring<T>::size() const {
    return m_size;
}

template<typename T>
void Ring<T>::clear() {
    if (!m_head) {
        return;
    }

    Node* current = m_head->next;
    while (current != m_head) {
        Node* toDelete = current;
        current = current->next;
        delete toDelete;
    }

    delete m_head;
    m_head = nullptr;
    m_size = 0;
}

template<typename T>
void Ring<T>::push_back(const T& value) {
    Node* node = new Node(value);
    if (!m_head) {
        m_head = node;
        m_head->next = m_head;
        m_head->prev = m_head;
    } else {
        Node* tail = m_head->prev;
        tail->next = node;
        node->prev = tail;
        node->next = m_head;
        m_head->prev = node;
    }
    ++m_size;
}

template<typename T>
typename Ring<T>::iterator Ring<T>::begin() {
    return iterator(this, m_head);
}

template<typename T>
typename Ring<T>::iterator Ring<T>::end() {
    return iterator(this, nullptr);
}

template<typename T>
typename Ring<T>::iterator Ring<T>::begin() const {
    return iterator(const_cast<Ring<T>*>(this), m_head);
}

template<typename T>
typename Ring<T>::iterator Ring<T>::end() const {
    return iterator(const_cast<Ring<T>*>(this), nullptr);
}
