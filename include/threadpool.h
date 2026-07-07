#include <vector>
#include <thread>
#include <atomic>
#include <mutex>

class ThreadPool{
    private:
        std::mutex mtx;
        std::atomic<bool> stop;
        std::vector<std::thread> threadsVec;
        std::condition_variable cv;
        void workerLoop();
    public:
        ThreadPool(int count);
        ~ThreadPool();
        ThreadPool(const ThreadPool& pool) = delete;
        ThreadPool& operator=(const ThreadPool& pool) = delete;
};