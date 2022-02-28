#include <thread>
#include <mutex>

#include <iostream>

std::mutex totalmutex;

int total; 
int number_ints = 100000;


void job_1(){
    for (int i = 0; i< number_ints; i++){
        // totalmutex.lock();
        total++;
        // totalmutex.unlock();

    }
}

void job_2(){
    for (int i = 0; i< number_ints; i++){
        // totalmutex.lock();
        total--;
        // totalmutex.unlock();

    }
}

int main(){
    std::thread thread_1(job_1);
    std::thread thread_2(job_2);

    thread_1.join();
    thread_2.join();


    std::cout << total << " hij werkt goed met mutex gap!" << std::endl; 
}