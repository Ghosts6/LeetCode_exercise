class StockSpanner:
    def __init__(self):
        self.stack = []

    def next(self, price: int) -> int:
        span = 1  

        while self.stack and self.stack[-1][0] <= price:
            span += self.stack.pop()[1]

        self.stack.append((price, span))
        
        return span

# Test case
if __name__ == "__main__":
    stockSpanner = StockSpanner()
    
    inputs = [100, 80, 60, 70, 60, 75, 85]

    print("Output:")

    for price in inputs:
        result = stockSpanner.next(price)
        print(result)