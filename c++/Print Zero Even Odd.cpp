#include <functional>
#include <mutex>
#include <condition_variable>
#include <iostream>
#include <thread>

class ZeroEvenOdd {
private:
    int n;
    std::mutex mtx;
    std::condition_variable cv;
    int state;
    int parity;

public:
    ZeroEvenOdd(int n) {
        this->n = n;
        state = 0;
        parity = 1;
    }

    void zero(std::function<void(int)> printNumber) {
        for (int i = 0; i < n; ++i) {
            std::unique_lock<std::mutex> lck(mtx);
            cv.wait(lck, [this]() { return state == 0; });
            state = 1;
            printNumber(0);
            cv.notify_all();
        }
    }

    void even(std::function<void(int)> printNumber) {
        for (int i = 2; i <= n; i += 2) {
            std::unique_lock<std::mutex> lck(mtx);
            cv.wait(lck, [this]() { return state == 1 && parity == 0; });
            state = 0;
            parity = 1;
            printNumber(i);
            cv.notify_all();
        }
    }

    void odd(std::function<void(int)> printNumber) {
        for (int i = 1; i <= n; i += 2) {
            std::unique_lock<std::mutex> lck(mtx);
            cv.wait(lck, [this]() { return state == 1 && parity == 1; });
            state = 0;
            parity = 0;
            printNumber(i);
            cv.notify_all();
        }
    }
};
// test case
int main() {
    int n = 5;
    ZeroEvenOdd zeo(n);

    auto printNumber = [](int num) { std::cout << num; };

    std::thread t1([&]() { zeo.zero(printNumber); });
    std::thread t2([&]() { zeo.even(printNumber); });
    std::thread t3([&]() { zeo.odd(printNumber); });

    t1.join();
    t2.join();
    t3.join();

    return 0;
}
