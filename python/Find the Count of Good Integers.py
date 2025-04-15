from itertools import permutations
from collections import Counter

class Solution:
    def countGoodIntegers(self, n: int, k: int) -> int:
        self.k = k
        self.n = n
        self.cache = set()
        return self.count_valid()

    def is_valid_palindrome(self, digits):
        """Check if we can rearrange digits to form a palindrome."""
        count = Counter(digits)
        odd_counts = sum(1 for v in count.values() if v % 2)
        if self.n % 2 == 0:
            return odd_counts == 0
        else:
            return odd_counts == 1

    def generate_palindromes(self, digits):
        """Generate all unique palindrome numbers from digits."""
        count = Counter(digits)
        half = []
        middle = ''
        for digit in sorted(count.keys()):
            times = count[digit] // 2
            half.extend([digit] * times)
            if count[digit] % 2 == 1:
                middle = digit

        palindromes = set()
        for perm in set(permutations(half)):
            if not perm or perm[0] == '0':
                continue
            half_str = ''.join(perm)
            full = half_str + middle + half_str[::-1]
            if full[0] != '0' and int(full) % self.k == 0:
                palindromes.add(full)
        return palindromes

    def count_valid(self):
        if self.n == 1:
            return sum(1 for i in range(1, 10) if i % self.k == 0)
        
        count = 0
        start = 10 ** (self.n - 1)
        end = 10 ** self.n

        for num in range(start, end):
            s = str(num)
            key = ''.join(sorted(s))
            if key in self.cache:
                count += 1
                continue

            if not self.is_valid_palindrome(s):
                continue

            palindromes = self.generate_palindromes(s)
            if palindromes:
                self.cache.add(key)
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