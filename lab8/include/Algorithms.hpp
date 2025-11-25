#pragma once

#include "Ring.hpp"
#include "Iterator.hpp"

template<typename T>
class RingAlgorithms {
public:
    static RingIterator<T> find(Ring<T>& ring, const T& value) {
        for (auto it = ring.begin(); it != ring.end(); ++it) {
            if (*it == value) {
                return it;
            }
        }
        return ring.end();
    }

    static void sort(Ring<T>& ring, bool ascending = true) {
        if (ring.size() < 2) {
            return;
        }

        bool swapped;
        do {
            swapped = false;
            auto it = ring.begin();
            if (it == ring.end()) {
                break;
            }

            auto next = it;
            ++next;

            while (next != ring.end()) {
                bool needSwap = ascending ? (*it > *next) : (*it < *next);
                if (needSwap) {
                    T tmp = *it;
                    *it = *next;
                    *next = tmp;
                    swapped = true;
                }
                ++it;
                ++next;
            }
        } while (swapped);
    }
};
