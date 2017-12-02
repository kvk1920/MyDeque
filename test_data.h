//
// Created by kvk on 12/2/17.
//

#ifndef D_TASK_TEST_DATA_H
#define D_TASK_TEST_DATA_H

#include "test_utility.h"

TEST(data_case, input10000)
{
    Deque <int> a;
    std::deque <int> b;
    for (size_t i(0); i < 10000; ++i)
    {
        doComand <int, Deque <int> >(a, test10000.comands[i]);
        doComand <int, std::deque <int> >(b, test10000.comands[i]);
        EXPECT_TRUE(dequeEQ <int> (a, b));
    }
}

TEST(data_case, input1000)
{
    Deque <int> a;
    std::deque <int> b;
    for (size_t i(0); i < 1000; ++i)
    {
        doComand <int, Deque <int> >(a, test1000.comands[i]);
        doComand <int, std::deque <int> >(b, test1000.comands[i]);
        EXPECT_TRUE(dequeEQ <int> (a, b));
    }
}

#define rand_data_test(test_name) \
    TEST(data_case, test_name) \
    { \
        TestInput <int> currentTest(10000);\
        Deque <int> a; \
        std::deque <int> b; \
        for (size_t i(0); i < 10000; ++i) \
        { \
            doComand <int, Deque <int> >(a, currentTest.comands[i]); \
            doComand <int, std::deque <int> >(b, currentTest.comands[i]); \
            EXPECT_TRUE(dequeEQ <int> (a, b)); \
        } \
    } \

rand_data_test(rand1)

rand_data_test(rand2)

rand_data_test(rand3)

#endif //D_TASK_TEST_DATA_H
