class Solution:
    def numWaterBottles(self, numBottles: int, numExchange: int) -> int:
        """
        return the maximum number of water bottles you can drink.
        """
        total = numBottles
        empty = numBottles
        while empty >= numExchange:
            new = empty // numExchange
            empty = empty % numExchange + new
            total += new
        return total

# test cases
if __name__ == "__main__":
    sol = Solution()

    # case 1
    numBottles = 9
    numExchange = 3
    print(f"Result of test case 1 : {sol.numWaterBottles(numBottles, numExchange)}") # Expected 13

    # case 2
    numBottles2 = 15
    numExchange2 = 4
    print(f"Result of test case 2 : {sol.numWaterBottles(numBottles2, numExchange2)}") # Expected 19


