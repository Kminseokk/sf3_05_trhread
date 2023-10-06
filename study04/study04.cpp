#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

std::mutex mtx;
std::condition_variable cv;
bool dataReady = false;

void producer() {
    // 데이터를 생성하고 공유 변수를 설정
    std::cout << "producer" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(3));
    {
        std::lock_guard<std::mutex> lock(mtx);
        dataReady = true;
    }
    std::cout << "notify_one" << std::endl;
    //cv.notify_one();
    cv.notify_all();
}

void consumer() {
    std::cout << "consumer" << std::endl;
    std::unique_lock<std::mutex> lock(mtx);
    std::cout << "Wait Data" << std::endl;

    cv.wait(lock, [] { return dataReady; });
    // 데이터를 사용

    std::cout << "Data is ready!" << std::endl;
}

int main() {
    std::thread t1(producer);
    std::thread t2(consumer);
    std::thread t3(consumer);
    t1.join();
    t2.join();
    t3.join();
    return 0;
}