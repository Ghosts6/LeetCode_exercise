class Solution:
    def flowerGame(self, n: int, m: int) -> int:
        odds_n, evens_n = (n + 1) // 2, n // 2
        odds_m, evens_m = (m + 1) // 2, m // 2
        return odds_n * evens_m + evens_n * odds_m


# Test cases
if __name__ == "__main__":
    sol = Solution()

    # case 1
    n1, m1 = 3, 2
    print(f"Result of test case 1 : {sol.flowerGame(n1, m1)}")  # Expected 3

    # case 2 
    n2, m2 = 1, 1
    print(f"Result of test case 2 : {sol.flowerGame(n2, m2)}")  # Expected 0

