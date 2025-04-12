from math import factorial
from collections import defaultdict

class Solution:
    def countGoodIntegers(self, n: int, k: int) -> int:
        """
        Returns the number of n-digit integers that can be rearranged to form a k-palindromic number.
        """
        def is_palindrome_possible(freq, n):
            odd_count = sum(f % 2 for f in freq)
            return odd_count <= 1 if n % 2 else odd_count == 0

        def build_smallest_palindrome(freq, n):
            half = []
            mid = ''
            for d in range(10):
                half.extend([str(d)] * (freq[d] // 2))
                if freq[d] % 2 == 1:
                    mid = str(d)
            if half and half[0] == '0':
                return None
            half_str = ''.join(half)
            return int(half_str + mid + half_str[::-1])

        def count_digits(num):
            freq = [0] * 10
            for d in str(num):
                freq[int(d)] += 1
            return freq

        start = 10 ** (n - 1)
        end = 10 ** n
        count = 0

        for num in range(start, end):
            freq = count_digits(num)
            if not is_palindrome_possible(freq, n):
                continue
            pal = build_smallest_palindrome(freq, n)
            if pal is not None and pal % k == 0:
                count += 1

        return count
# Main space
if __name__ == "__main__":
    solution = Solution()
    # case 1
    n1, k1 = 3, 5
    print(f"Result of test case 1 is : {solution.countGoodIntegers(n1, k1)}") # Expected Output: 27

    # case 2
    n2, k2 = 1, 4
    print(f"Result of test case 2 is : {solution.countGoodIntegers(n2, k2)}") # Expected Output: 2

    # case 3
    n3, k3 = 5, 6
    print(f"Result of test case 3 is : {solution.countGoodIntegers(n3, k3)}") # Expected Output: 2468