#include <iostream>
#include <thread>
#include <mutex>

std::mutex mtx;
int a = 0;
int b = 0;

void someFunction() {
    mtx.lock();
    // 공유 데이터에 대한 안전한 작업 수행
    for (int i = 0; i < 10; i++) {
        a += 1;
        std::cout << "someF's [a] " << a << std::endl;
    }
   mtx.unlock();
}

void multFunction() {
    //mtx.lock();
    // 공유 데이터에 대한 안전한 작업 수행
    for (int i = 0; i < 10; i++) {
        a = a + 7;
        std::cout << "multF's [a] " <<  a << std::endl;
    }
    //mtx.unlock();
}


void bmultFunction() {
    //mtx.lock();
    // 공유 데이터에 대한 안전한 작업 수행
    for (int i = 0; i < 10; i++) {
        b = b + 7;
        std::cout << "multF's [a] " << b << std::endl;
    }
    //mtx.unlock();
}

int main() {
    std::thread t1(someFunction);
    std::thread t2(bmultFunction);

    t1.join();
    t2.join();

    //std::cout << "2 언제 실행되나요? " << std::endl;

    return 0;
}