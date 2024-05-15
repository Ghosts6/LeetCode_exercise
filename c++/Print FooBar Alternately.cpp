#include <functional>
#include <mutex>
#include <thread>

class FooBar {
private:
    int n;
    std::mutex mtx;
    bool isFooTurn;

public:
    FooBar(int n) {
        this->n = n;
        isFooTurn = true;
    }

    void foo(std::function<void()> printFoo) {
        for (int i = 0; i < n; i++) {
            std::unique_lock<std::mutex> lock(mtx);
            while (!isFooTurn) {
                lock.unlock();
                std::this_thread::yield();
                lock.lock();
            }
            printFoo();
            isFooTurn = false;
            lock.unlock();
        }
    }

    void bar(std::function<void()> printBar) {
        for (int i = 0; i < n; i++) {
            std::unique_lock<std::mutex> lock(mtx);
            while (isFooTurn) {
                lock.unlock();
                std::this_thread::yield();
                lock.lock();
            }
            printBar();
            isFooTurn = true;
            lock.unlock();
        }
    }
};
