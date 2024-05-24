# 📜 Print in Order

## 💡 Intuition
The problem requires us to ensure that three methods are executed in a specific order: first, second, and third. We use mutexes (or locks) to control the order of execution by blocking and releasing threads.

## 🛠️ Approach
1.  Initialization:
In the constructor, lock both mutexes mtx1 and mtx2 to ensure that second and third cannot execute until first and second respectively, have been called.
2.  Execution Order:
first unlocks mtx1 after executing, allowing second to proceed.
second locks mtx1 and unlocks mtx2 after executing, allowing third to proceed.
third locks mtx2 to ensure it can only proceed after second has executed.

## ⏰ Complexity
- Time complexity:
O(1) for each method call. The operations performed within each method are constant time operations.

- Space complexity:
O(1) excluding the space required for the Foo object. The space used by the locks is minimal and constant.

## 💻 Code
### c++
```cpp
class Foo {
private:
    mutex mtx1;
    mutex mtx2;
public:
    Foo() {
        mtx1.lock(); 
        mtx2.lock(); 
    }

    void first(function<void()> printFirst) {
        printFirst();
        mtx1.unlock(); 
    }

    void second(function<void()> printSecond) {
        mtx1.lock(); 
        printSecond();
        mtx2.unlock(); 
    }

    void third(function<void()> printThird) {
        mtx2.lock();
        printThird();
    }
};
```
### C
```c
typedef struct {
    pthread_mutex_t lock;
    pthread_cond_t cond1;
    pthread_cond_t cond2;
    int state;
} Foo;

Foo* fooCreate() {
    Foo* obj = (Foo*) malloc(sizeof(Foo));
    
    pthread_mutex_init(&obj->lock, NULL);
    pthread_cond_init(&obj->cond1, NULL);
    pthread_cond_init(&obj->cond2, NULL);
    obj->state = 0;
    
    return obj;
}

void first(Foo* obj) {
    pthread_mutex_lock(&obj->lock);
    printFirst();
    
    obj->state = 1;
    pthread_cond_signal(&obj->cond1);
    pthread_mutex_unlock(&obj->lock);
}

void second(Foo* obj) {
    pthread_mutex_lock(&obj->lock);

    while (obj->state < 1) {
        pthread_cond_wait(&obj->cond1, &obj->lock);
    }
    printSecond();
    
    obj->state = 2;
    pthread_cond_signal(&obj->cond2);
    pthread_mutex_unlock(&obj->lock);
}

void third(Foo* obj) {
    pthread_mutex_lock(&obj->lock);

    while (obj->state < 2) {
        pthread_cond_wait(&obj->cond2, &obj->lock);
    }
    printThird();
    
    pthread_mutex_unlock(&obj->lock);
}

void fooFree(Foo* obj) {
    pthread_mutex_destroy(&obj->lock);
    pthread_cond_destroy(&obj->cond1);
    pthread_cond_destroy(&obj->cond2);
    free(obj);
}
```
### python
```py
class Foo:
    def __init__(self):
        self.mtx1 = threading.Lock()
        self.mtx2 = threading.Lock()
        self.mtx1.acquire()
        self.mtx2.acquire()

    def first(self, printFirst: 'Callable[[], None]') -> None:
        printFirst()
        self.mtx1.release()

    def second(self, printSecond: 'Callable[[], None]') -> None:
        self.mtx1.acquire()
        printSecond()
        self.mtx2.release()

    def third(self, printThird: 'Callable[[], None]') -> None:
        self.mtx2.acquire()
        printThird()
```