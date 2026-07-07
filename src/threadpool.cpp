#include "threadpool.h"

ThreadPool::ThreadPool(int count): stop{false}{
    for (int i = 0; i < count; i++)
    {
        threadsVec.emplace_back(&ThreadPool::workerLoop, this);
    }
}

void ThreadPool::workerLoop(){
    std::unique_lock<std::mutex> lck(mtx);
     cv.wait(lck, [this] {
         return (stop == true);
     });
}

ThreadPool::~ThreadPool(){
    {
        std::unique_lock<std::mutex> lck(mtx);
        stop = true;
    }
    cv.notify_all();
    for(auto &thr : threadsVec){
        if(thr.joinable()) thr.join();
    }
}