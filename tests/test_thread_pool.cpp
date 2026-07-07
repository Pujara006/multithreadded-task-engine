#include "threadpool.h"

#include <iostream>
#include <thread>
#include <chrono>

void testBasicCreateDestroy()
{
    std::cout << "Test 1: Basic create/destroy started\n";

    {
        ThreadPool pool(4);
        std::cout << "ThreadPool with 4 threads created\n";
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "Leaving scope now\n";
    }

    std::cout << "Test 1 passed: ThreadPool destroyed safely\n\n";
}

void testDifferentThreadCounts()
{
    std::cout << "Test 2: Different thread counts started\n";

    {
        ThreadPool pool(1);
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }

    {
        ThreadPool pool(2);
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }

    {
        ThreadPool pool(4);
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }

    {
        ThreadPool pool(8);
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }

    std::cout << "Test 2 passed: Different thread counts destroyed safely\n\n";
}

void testRepeatedCreateDestroy()
{
    std::cout << "Test 3: Repeated create/destroy started\n";

    for (int i = 0; i < 100; i++) {
        ThreadPool pool(4);
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }

    std::cout << "Test 3 passed: Repeated create/destroy completed safely\n\n";
}

void testLargeThreadCount()
{
    std::cout << "Test 4: Large thread count started\n";

    {
        ThreadPool pool(32);
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    std::cout << "Test 4 passed: 32-thread pool destroyed safely\n\n";
}

void testLongIdleSleep()
{
    std::cout << "Test 5: Long idle sleep test started\n";

    {
        ThreadPool pool(16);
        std::cout << "ThreadPool with 16 threads sleeping for 5 seconds\n";
        std::this_thread::sleep_for(std::chrono::seconds(5));
        std::cout << "Leaving long idle scope now\n";
    }

    std::cout << "Test 5 passed: Long idle pool destroyed safely\n\n";
}

void testRapidCreateDestroyNoSleep()
{
    std::cout << "Test 6: Rapid create/destroy with no sleep started\n";

    for (int i = 0; i < 1000; i++) {
        ThreadPool pool(4);
    }

    std::cout << "Test 6 passed: Rapid create/destroy completed safely\n\n";
}

int main()
{
    std::cout << "Starting Phase 1 Task 2 tests...\n\n";

    testBasicCreateDestroy();
    testDifferentThreadCounts();
    testRepeatedCreateDestroy();
    testLargeThreadCount();
    testLongIdleSleep();
    testRapidCreateDestroyNoSleep();
    std::cout << "All Phase 1 Task 2 tests passed.\n";
    return 0;
}