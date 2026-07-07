#include <vector>
#include <thread>
#include <atomic>

class ThreadPool{
    private:
        std::atomic<bool> stop;
        std::vector<std::thread> threadsVec;
        void workerLoop();
    public:
        ThreadPool(int count);
        ~ThreadPool();
        ThreadPool(const ThreadPool& pool) = delete;
        ThreadPool& operator=(const ThreadPool& pool) = delete;
};