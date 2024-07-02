from collections import deque

class RecentCounter:

    def __init__(self):
        self.requests = deque()

    def ping(self, t: int) -> int:
        self.requests.append(t)
        while self.requests and self.requests[0] < t - 3000:
            self.requests.popleft()
        return len(self.requests)

# test cases
if __name__ == "__main__":
    recentCounter = RecentCounter()
    print(recentCounter.ping(1))    
    print(recentCounter.ping(100))  
 
