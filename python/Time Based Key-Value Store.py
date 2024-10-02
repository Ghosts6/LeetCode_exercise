class TimeMap:
    def __init__(self):
        self.store = {}
        
    def set(self, key: str, value: str, timestamp: int) -> None:
        if key not in self.store:
            self.store[key] = []
        self.store[key].append((timestamp, value))
        
    def get(self, key: str, timestamp: int) -> str:
        if key not in self.store:
            return ""
        
        values = self.store[key]
        left, right = 0, len(values) - 1
        while left <= right:
            mid = (left + right) // 2
            if values[mid][0] <= timestamp:
                left = mid + 1
            else:
                right = mid - 1
        
        if right >= 0:
            return values[right][1]
        else:
            return ""
# Test cases
if __name__ == "__main__":
    
    timeMap = TimeMap()
    
    timeMap.set("foo", "bar", 1)      # store key "foo" and value "bar" at timestamp 1
    print(timeMap.get("foo", 1))      # returns "bar"
    print(timeMap.get("foo", 3))      # returns "bar"
    
    timeMap.set("foo", "bar2", 4)     # store key "foo" and value "bar2" at timestamp 4
    print(timeMap.get("foo", 4))      # returns "bar2"
    print(timeMap.get("foo", 5))      # returns "bar2"
