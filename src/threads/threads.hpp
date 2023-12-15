#ifndef THREADS_HPP
#define THREADS_HPP

#include <mutex>
#include <condition_variable>
#include <memory>

extern std::mutex coutMutex;
extern std::condition_variable cv;
extern bool ready;

void workerThread(int id);

class SharedResource {
private:
    std::mutex mutex_;

public:
    void accessResource(int threadId);
};

void smartPointerExample();

#endif // THREADS_HPP
