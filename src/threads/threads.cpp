#include <iostream>
#include "threads.hpp"

std::mutex coutMutex;
std::condition_variable cv;
bool ready = false;

void workerThread(int id) {
    std::unique_lock<std::mutex> lock(coutMutex);
    std::cout << "Thread " << id << " is waiting." << std::endl;

    cv.wait(lock, [] { return ready; });

    std::cout << "Thread " << id << " is working." << std::endl;
}

void SharedResource::accessResource(int threadId) {
    std::lock_guard<std::mutex> lock(mutex_);
    std::cout << "Thread " << threadId << " is accessing the shared resource." << std::endl;
}

void smartPointerExample() {
    std::shared_ptr<int> smartIntPointer = std::make_shared<int>(42);
    std::cout << "Smart Pointer Value: " << *smartIntPointer << std::endl;
}
