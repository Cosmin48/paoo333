#include <iostream>
#include <unistd.h>
#include "threads.hpp"

std::mutex coutMutex;//asigura că ieșirea la consolă este afișată în mod corespunzător de către firele concurente.
std::condition_variable cv;//Declaram o variabilă condițională (cv) care va fi folosită pentru a sincroniza activitățile dintre firele de execuție.
bool ready = false;//Declaram o variabilă booleană (ready) care va fi modificată pentru a notifica celelalte fire când pot începe să lucreze.

void workerThread(int id) {//Definim o funcție workerThread care primește un identificator (id) pentru a ilustra un fir de execuție.
    std::unique_lock<std::mutex> lock(coutMutex);//Creăm un std::unique_lock pe mutex-ul coutMutex. Acest lucru asigură că ieșirea la consolă este sincronizată între fire.
    std::cout << "Thread " << id << " is waiting." << std::endl;

    cv.wait(lock, [] { return ready; });//Folosim cv.wait pentru a bloca firul de execuție până când variabila ready devine true. În acest timp, mutex-ul este eliberat automat.

    std::cout << "Thread " << id << " is working." << std::endl;
    sleep(5);
    std::cout<<"Thread is finished"<<std::endl;
}

void SharedResource::accessResource(int threadId) {
    std::lock_guard<std::mutex> lock(mutex_);
    std::cout << "Thread " << threadId << " is accessing the shared resource." << std::endl;
}

void smartPointerExample() {
    std::shared_ptr<int> smartIntPointer = std::make_shared<int>(42);
    std::cout << "Smart Pointer Value: " << *smartIntPointer << std::endl;
}
