// wrong answer time limit problem 
#include <functional>
#include <mutex>
#include <condition_variable>
#include <iostream>
#include <thread>

class ZeroEvenOdd {
private:
    int n;
    int count;
    std::mutex mtx;
    std::condition_variable cv;
    int turn;

public:
    ZeroEvenOdd(int n) : n(n), count(1), turn(1) {}

    void zero(std::function<void(int)> printNumber) {
        std::unique_lock<std::mutex> lock(mtx);
        while (count <= n) {
            while (turn != 1 && count <= n) {
                cv.wait(lock);
            }
            if (count <= n) {
                printNumber(0);
                if (count % 2 == 0)
                    turn = 2;
                else
                    turn = 3;
                count++;
                cv.notify_all();
            }
        }
    }

    void even(std::function<void(int)> printNumber) {
        std::unique_lock<std::mutex> lock(mtx);
        while (count <= n) {
            while (turn != 2 && count <= n) {
                cv.wait(lock);
            }
            if (count <= n && count % 2 == 0) {
                printNumber(count);
                count++;
                turn = 1;
                cv.notify_all();
            }
            else {
                cv.notify_all();
            }
        }
    }

    void odd(std::function<void(int)> printNumber) {
        std::unique_lock<std::mutex> lock(mtx);
        while (count <= n) {
            while (turn != 3 && count <= n) {
                cv.wait(lock);
            }
            if (count <= n && count % 2 != 0) {
                printNumber(count);
                count++;
                turn = 1;
                cv.notify_all();
            }
            else {
                cv.notify_all();
            }
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
