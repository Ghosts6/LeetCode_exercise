class Solution:
    def lexicalOrder(self, n: int) -> list[int]:
        result = []
        current = 1
        
        for _ in range(n):
            result.append(current)
            if current * 10 <= n:
                current *= 10
            else:
                if current >= n:
                    current //= 10
                current += 1
                while current % 10 == 0:
                    current //= 10
                    
        return result

# Test cases
if __name__ == "__main__":
    solution = Solution()

    # case 1
    print(f"result of test case 1 is : {solution.lexicalOrder(13)}") # Expected: [1,10,11,12,13,2,3,4,5,6,7,8,9]

    # case 2
    print(f"result of test case 2 is : {solution.lexicalOrder(2)}") # Expected: [1,2]
