#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include "easyfind.h"

static void testVector() {
    std::vector<int> v;
    for (int i = 0; i < 10; ++i) v.push_back(i * 2);
    std::cout << "Vector contents:";
    for (size_t i = 0; i < v.size(); ++i) std::cout << ' ' << v[i];
    std::cout << '\n';
    try {
        std::vector<int>::iterator it = easyfind(v, 14);
        std::cout << "Found 14 at index " << (it - v.begin()) << '\n';
    } catch (const std::exception &e) {
        std::cout << "Search failed: " << e.what() << '\n';
    }
    try {
        easyfind(v, 15);
        std::cout << "Found 15 (unexpected)" << '\n';
    } catch (const std::exception &e) {
        std::cout << "15 not found: " << e.what() << '\n';
    }
}

static void testList() {
    std::list<int> lst;
    for (int i = 1; i <= 5; ++i) lst.push_back(i);
    std::cout << "List contents:";
    for (std::list<int>::const_iterator it = lst.begin(); it != lst.end(); ++it) std::cout << ' ' << *it;
    std::cout << '\n';
    try {
        std::list<int>::iterator it = easyfind(lst, 3);
        std::cout << "Found 3 value=" << *it << '\n';
    } catch (const std::exception &e) {
        std::cout << "Search failed: " << e.what() << '\n';
    }
    try {
        easyfind(lst, 10);
    } catch (const std::exception &e) {
        std::cout << "10 not found: " << e.what() << '\n';
    }
}

static void testDeque() {
    std::deque<int> dq;
    for (int i = 0; i < 7; ++i) dq.push_back(i + 5); // 5 6 7 8 9 10 11
    std::cout << "Deque contents:";
    for (std::deque<int>::const_iterator it = dq.begin(); it != dq.end(); ++it) std::cout << ' ' << *it;
    std::cout << '\n';
    try {
        std::deque<int>::iterator it = easyfind(dq, 9);
        std::cout << "Found 9 value=" << *it << '\n';
    } catch (const std::exception &e) {
        std::cout << "Search failed: " << e.what() << '\n';
    }
    try {
        easyfind(dq, 1);
    } catch (const std::exception &e) {
        std::cout << "1 not found: " << e.what() << '\n';
    }
}

int main() {
    std::cout << "== easyfind tests ==" << '\n';
    testVector();
    std::cout << '\n';
    testList();
    std::cout << '\n';
    testDeque();
    return 0;
}
