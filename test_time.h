//
// Created by kvk on 12/2/17.
//

#ifndef D_TASK_TEST_TIME_H
#define D_TASK_TEST_TIME_H

#include "test_utility.h"

TEST(time_case, Deque_rand)
{
    Deque <int> a;
    for (int i(0); i < 1000000; ++i)
        doComand <int, Deque <int> >(a, test1000000.comands[i]);
}

TEST(time_case, std_deque_rand)
{
    std::deque <int> a;
    for (int i(0); i < 1000000; ++i)
        doComand <int, std::deque <int> >(a, test1000000.comands[i]);
}

TEST(time_case, Deque_sort)
{
    Deque <int> a;
    for (int i(0); i < 1000000; ++i)
        a.push_back(test1000000.comands[i].data);
    std::sort(std::begin(a), std::end(a));
}

TEST(time_case, std_deque_sort)
{
    std::deque <int> a;
    for (int i(0); i < 1000000; ++i)
        a.push_back(test1000000.comands[i].data);
    std::sort(std::begin(a), std::end(a));
}

TEST(time_case, input100)
{
    Deque <int> a;
    for (size_t i(0); i < 100; ++i)
        a.push_back(test100.comands[i].data);
    while (!a.empty())
        a.pop_back();
}

TEST(time_case, input1000)
{
    Deque <int> a;
    for (size_t i(0); i < 1000; ++i)
        a.push_back(test1000.comands[i].data);
    while (!a.empty())
        a.pop_back();
}

TEST(time_case, input10000)
{
    Deque <int> a;
    for (size_t i(0); i < 10000; ++i)
        a.push_back(test10000.comands[i].data);
    while (!a.empty())
        a.pop_back();
}

TEST(time_case, input100000)
{
    Deque <int> a;
    for (size_t i(0); i < 100000; ++i)
        a.push_back(test100000.comands[i].data);
    while (!a.empty())
        a.pop_back();
}

TEST(time_case, input1000000)
{
    Deque <int> a;
    for (size_t i(0); i < 1000000; ++i)
        a.push_back(test1000000.comands[i].data);
    while (!a.empty())
        a.pop_back();
}

TEST(time_case, input10000000)
{
    Deque <int> a;
    for (size_t i(0); i < 10000000; ++i)
        a.push_back(test10000000.comands[i].data);
    while (!a.empty())
        a.pop_back();
}

TEST(time_case, input100000000)
{
    Deque <int> a;
    for (size_t i(0); i < 100000000; ++i)
        a.push_back(test100000000.comands[i].data);
    while (!a.empty())
        a.pop_back();
}

TEST(time_case, std_input100000000)
{
    std::deque <int> a;
    for (size_t i(0); i < 100000000; ++i)
        a.push_back(test100000000.comands[i].data);
    while (!a.empty())
        a.pop_back();
}

#endif //D_TASK_TEST_TIME_H
