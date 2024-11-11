from typing import List

class Solution:
    def __init__(self):
        self.primes = self._sieve_of_eratosthenes(1000)
    
    def _sieve_of_eratosthenes(self, limit: int) -> List[int]:
        is_prime = [True] * (limit + 1)
        primes = []
        for i in range(2, limit + 1):
            if is_prime[i]:
                primes.append(i)
                for j in range(i * i, limit + 1, i):
                    is_prime[j] = False
        return primes
    
    def primeSubOperation(self, nums: List[int]) -> bool:
        prev = nums[0]

        for i in range(1, len(nums)):
            if nums[i] > prev:
                prev = nums[i]
                continue

            possible = False
            for p in self.primes:
                if p >= nums[i]: 
                    break
                if nums[i] - p > prev:
                    nums[i] -= p
                    prev = nums[i]  
                    possible = True
                    break
                
            if not possible:
                return False
        
        return True
# Test cases
if __name__ == "__main__":
    sol = Solution()
    
    # case 1
    nums1 = [4,9,6,10]
    print(sol.canBeIncreasing(nums1))  # Output: True

    # case 2
    nums2 = [6,8,11,12]
    print(sol.canBeIncreasing(nums2))  # Output: True

    # case 3
    nums3 = [5,8,3]
    print(sol.canBeIncreasing(nums3))  # Output: False