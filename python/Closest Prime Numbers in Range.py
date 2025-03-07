from typing import List

class Solution:
    def closestPrimes(self, left: int, right: int) -> List[int]:
        limit = right + 1 
        is_prime = [True] * (limit)
        is_prime[0] = is_prime[1] = False 
        
        for num in range(2, int(limit ** 0.5) + 1):
            if is_prime[num]:  
                for multiple in range(num * num, limit, num):
                    is_prime[multiple] = False

        primes = [num for num in range(left, right + 1) if is_prime[num]]

        if len(primes) < 2:
            return [-1, -1]
        
        min_diff = float('inf')
        closest_pair = [-1, -1]
        
        for i in range(len(primes) - 1):
            diff = primes[i + 1] - primes[i]
            if diff < min_diff:
                min_diff = diff
                closest_pair = [primes[i], primes[i + 1]]
        
        return closest_pair

# Test cases
if __name__ == "__main__":
    solution = Solution()
    # case 1
    left1, right1 = 10, 19
    print(f"Closest prime numbers in range {left1} to {right1} are {solution.closestPrimes(left1, right1)}") # Expected Output: [11, 13]

    # case 2
    left2, right2 = 4, 6
    print(f"Closest prime numbers in range {left2} to {right2} are {solution.closestPrimes(left2, right2)}") # Expected Output: [-1,-1]
