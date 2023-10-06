#include <iostream>
#include <thread>
#include <atomic>

std::atomic<int> counter(0);

void increment() {
    for (int i = 0; i < 10; ++i) {
        //counter.fetch_add(1, std::memory_order_relaxed);
        counter++;
    }
    std::cout << "counter: " << counter << std::endl;
    counter = counter * 2;
}

int main() {
    std::thread t1(increment);
    std::thread t2(increment);
    t1.join();
    t2.join();
    //std::cout << "Counter: " << counter.load(std::memory_order_relaxed) << std::endl;
    std::cout << "Counter: " << counter << std::endl;
    return 0;
}