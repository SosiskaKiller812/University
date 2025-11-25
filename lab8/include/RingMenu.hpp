#pragma once

#include <iostream>
#include <string>

#include "Ring.hpp"
#include "Iterator.hpp"
#include "Algorithms.hpp"
#include "Utilities.hpp"

template<typename T>
void ringMenu() {
    Ring<T> ring;

    while (true) {
        system("cls");
        std::cout << "1. Add element" << std::endl;
        std::cout << "2. Show ring" << std::endl;
        std::cout << "3. Find element" << std::endl;
        std::cout << "4. Sort ascending" << std::endl;
        std::cout << "5. Sort descending" << std::endl;
        std::cout << "0. Exit" << std::endl;

        char option;
        std::cin >> option;

        switch (option) {
        case '1': {
            std::cout << "Enter value: ";
            T value = getValue<T>();
            ring.push_back(value);
            break;
        }
        case '2': {
            if (ring.empty()) {
                std::cout << "Ring is empty" << std::endl;
            } else {
                std::cout << "Your ring: ";
                for (auto it = ring.begin(); it != ring.end(); ++it) {
                    std::cout << *it << ' ';
                }
                std::cout << std::endl;
            }
            system("pause");
            break;
        }
        case '3': {
            if (ring.empty()) {
                std::cout << "Ring is empty" << std::endl;
                system("pause");
                break;
            }
            std::cout << "Enter value to find: ";
            T value = getValue<T>();
            auto found = RingAlgorithms<T>::find(ring, value);
            if (found != ring.end()) {
                std::cout << "Element was found!" << std::endl;
            } else {
                std::cout << "Element not found." << std::endl;
            }
            system("pause");
            break;
        }
        case '4': {
            RingAlgorithms<T>::sort(ring, true);
            std::cout << "Sorted ascending." << std::endl;
            system("pause");
            break;
        }
        case '5': {
            RingAlgorithms<T>::sort(ring, false);
            std::cout << "Sorted descending." << std::endl;
            system("pause");
            break;
        }
        case '0':
            return;
        default:
            std::cout << "Invalid input!" << std::endl;
            system("pause");
        }
    }
}

inline void showTypeChoice() {
    std::cout << "Choose type for ring:" << std::endl;
    std::cout << "1. int" << std::endl;
    std::cout << "2. double" << std::endl;
    std::cout << "3. char" << std::endl;
    std::cout << "4. std::string" << std::endl;
}

inline void startWorkWithRing() {
    showTypeChoice();

    char option;
    do {
        std::cin >> option;
    } while (option < '1' || option > '4');

    if (option == '1') {
        ringMenu<int>();
    } else if (option == '2') {
        ringMenu<double>();
    } else if (option == '3') {
        ringMenu<char>();
    } else if (option == '4') {
        ringMenu<std::string>();
    } else {
        std::cout << "Invalid value, try again" << std::endl;
    }
}


