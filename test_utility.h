//
// Created by kvk on 12/2/17.
//

#ifndef D_TASK_TEST_UTILITY_H
#define D_TASK_TEST_UTILITY_H

#include "deque.h"
#include <deque>
#include <cstdlib>
#include <algorithm>

template <typename T>
struct Comand
{
    int comand; T data;
};

template <typename T>
struct TestInput
{
    const size_t _Size_;

    Comand <T> *comands;

    TestInput(size_t _Size_) : _Size_(_Size_), comands(new Comand <T>[_Size_])
    {
        for (size_t i(0); i < _Size_; ++i)
            comands[i].comand = rand(), comands[i].data = rand();
    }

    ~TestInput()
    {
        delete [] comands;
    }
};

TestInput <int> test100(100), test1000(1000), test10000(10000), test100000(100000), test1000000(1000000), test10000000(10000000), test100000000(100000000);

template <typename value_type, class deque_type>
void doComand(deque_type &a, const Comand <value_type> comand)
{
    int comandType;
    if (a.empty())
        comandType = comand.comand % 2;
    else if (comand.comand % 100 > 80)
        comandType = 2 + (comand.comand % 100 - 100) / 10;
    else comandType = comand.comand % 100 / 40;
    switch (comandType)
    {
        case 0: a.push_back(comand.data); break;
        case 1: a.push_front(comand.data); break;
        case 2: a.pop_back(); break;
        case 3: a.pop_front(); break;
        default: break;
    }
}

template <typename T>
bool dequeEQ(const Deque <T> &a, const std::deque <T> &b)
{
    if (a.size() != b.size())
        return false;
    typename Deque <T>::const_iterator it1(a.cbegin());
    typename std::deque <T>::const_iterator it2(b.cbegin());

    while (it1 != a.cend())
    {
        if (*it1 != *it2)
            return false;
        ++it1, ++it2;
    }
    return true;
}

#endif //D_TASK_TEST_UTILITY_H
