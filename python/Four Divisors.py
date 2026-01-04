from typing import List

class Solution:
    def sumFourDivisors(self, nums: List[int]) -> int:
        """Return sum of divisors for number with exactly four divisors on giving list"""
        total = 0

        for n in nums:
            if n <= 1:
                continue

            div_sum = 0
            div_count = 0

            i = 1
            while i * i <= n:
                if n % i == 0:
                    j = n // i

                    div_count += 1
                    div_sum += i

                    if j != i:
                        div_count += 1
                        div_sum += j

                    if div_count > 4:
                        break

                i += 1

            if div_count == 4:
                total += div_sum

        return total

# Test cases
if __name__ == "__main__":
    sol = Solution()

    # case 1
    nums1 = [21, 4, 7]
    print(f"Result of test case 1 : {sol.sumFourDivisors(nums1)}") # Expected: 32

    # case 2
    nums2 = [21, 21]
    print(f"Result of test case 2 : {sol.sumFourDivisors(nums2)}") # Expected: 64

    # case 3
    nums3 = [1, 2, 3, 4, 5]
    print(f"Result of test case 3 : {sol.sumFourDivisors(nums3)}") # Expected: 0
