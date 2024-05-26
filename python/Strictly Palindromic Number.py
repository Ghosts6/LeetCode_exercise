class Solution:
    def isStrictlyPalindromic(self, n: int) -> bool:
        if n <= 2:
            return True
        for base in range(2, n - 1):
            if not self.isPalindromic(n, base):
                return False
        return True

    def isPalindromic(self, n: int, base: int) -> bool:
        num_in_base = self.convertToBase(n, base)
        left, right = 0, len(num_in_base) - 1
        while left < right:
            if num_in_base[left] != num_in_base[right]:
                return False
            left += 1
            right -= 1
        return True

    def convertToBase(self, n: int, base: int) -> str:
        result = ""
        while n > 0:
            result = str(n % base) + result
            n //= base
        return result