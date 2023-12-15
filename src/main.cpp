#include <iostream>
#include <thread>  // Adăugată linia necesară
#include "threads/threads.hpp"

int main() {
    const int numThreads = 3;

    // Fire de execuție și semafor
    std::thread threads[numThreads];
    for (int i = 0; i < numThreads; ++i) {
        threads[i] = std::thread(workerThread, i + 1);
    }

    {
        std::lock_guard<std::mutex> lock(coutMutex);
        std::cout << "Main thread signals workers to start." << std::endl;
    }
    ready = true;
    cv.notify_all();

    for (int i = 0; i < numThreads; ++i) {
        threads[i].join();
    }

    SharedResource sharedResource;
    sharedResource.accessResource(0);

    smartPointerExample();

    return 0;
}
