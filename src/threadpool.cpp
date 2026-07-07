#include "threadpool.h"

ThreadPool::ThreadPool(int count): stop{false}{
    for (int i = 0; i < count; i++)
    {
        threadsVec.emplace_back(&ThreadPool::workerLoop, this);
    }
}

void ThreadPool::workerLoop(){
    while(!stop) {}
}

ThreadPool::~ThreadPool(){
    stop = true;
    for(auto &thr : threadsVec){
        if(thr.joinable()) thr.join();
    }
}