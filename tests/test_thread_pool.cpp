#include "threadpool.h"
#include <iostream>
#include <thread>
#include <chrono>

void testBasicCreateDestroy(){
    std::cout << "Test 1: Basic create/destroy started\n";
    {
        ThreadPool pool(4);
        std::cout << "ThreadPool with 4 threads created\n";
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "Leaving scope now\n";
    }
    std::cout << "Test 1 passed: ThreadPool destroyed safely\n";
}

void testDifferentThreadCounts(){
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
    std::cout << "Test 2 passed: Different thread counts destroyed safely\n";
}

void testRepeatedCreateDestroy(){
    std::cout << "Test 3: Repeated create/destroy started\n";
    for (int i = 0; i < 100; i++) {
        ThreadPool pool(4);
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
    std::cout << "Test 3 passed: Repeated create/destroy completed safely\n";
}

void testLargeThreadCount(){
    std::cout << "Test 4: Large thread count started\n";
    {
        ThreadPool pool(32);
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    std::cout << "Test 4 passed: 32-thread pool destroyed safely\n";
}

int main()
{
    std::cout << "Starting Phase 1 Task 1 tests...\n";
    testBasicCreateDestroy();
    testDifferentThreadCounts();
    testRepeatedCreateDestroy();
    testLargeThreadCount();
    std::cout << "All Phase 1 Task 1 tests passed.\n";
    return 0;
}