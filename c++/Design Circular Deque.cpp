#include <iostream>
#include <vector>

class MyCircularDeque {
public:
    MyCircularDeque(int k) : capacity(k + 1), deque(k + 1), front(0), rear(0) {
    }
    
    bool insertFront(int value) {
        if (isFull()) return false; 
        front = (front - 1 + capacity) % capacity;
        deque[front] = value;
        return true;
    }
    
    bool insertLast(int value) {
        if (isFull()) return false; 
        deque[rear] = value;
        rear = (rear + 1) % capacity;
        return true;
    }
    
    bool deleteFront() {
        if (isEmpty()) return false; 
        front = (front + 1) % capacity;
        return true;
    }
    
    bool deleteLast() {
        if (isEmpty()) return false; 
        rear = (rear - 1 + capacity) % capacity;
        return true;
    }
    
    int getFront() {
        if (isEmpty()) return -1;
        return deque[front];
    }
    
    int getRear() {
        if (isEmpty()) return -1;
        return deque[(rear - 1 + capacity) % capacity];
    }
    
    bool isEmpty() {
        return front == rear;
    }
    
    bool isFull() {
        return (rear + 1) % capacity == front;
    }

private:
    int capacity;
    std::vector<int> deque;
    int front;
    int rear;
};
//  Test case
int main() {
    MyCircularDeque myCircularDeque(3);

    std::cout << std::boolalpha << myCircularDeque.insertLast(1) << std::endl;  // return True
    std::cout << std::boolalpha << myCircularDeque.insertLast(2) << std::endl;  // return True
    std::cout << std::boolalpha << myCircularDeque.insertFront(3) << std::endl; // return True
    std::cout << std::boolalpha << myCircularDeque.insertFront(4) << std::endl; // return False
    std::cout << myCircularDeque.getRear() << std::endl;                        // return 2
    std::cout << std::boolalpha << myCircularDeque.isFull() << std::endl;       // return True
    std::cout << std::boolalpha << myCircularDeque.deleteLast() << std::endl;   // return True
    std::cout << std::boolalpha << myCircularDeque.insertFront(4) << std::endl; // return True
    std::cout << myCircularDeque.getFront() << std::endl;                       // return 4
    
    return 0;
}
