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