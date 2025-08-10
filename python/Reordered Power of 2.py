class Solution:
    def reorderedPowerOf2(self, n: int) -> bool:
        def digit_signature(x):
            return ''.join(sorted(str(x)))

        power_signatures = {digit_signature(1 << i) for i in range(31)}
        return digit_signature(n) in power_signatures

# Test cases
if __name__ == "__main__":
    sol = Solution()
    # case 1
    print(f"Result of test case 1 : {sol.reorderedPowerOf2(1)}")   # True
    # case 2
    print(f"Result of test case 2 : {sol.reorderedPowerOf2(10)}")  # False
    # case 3
    print(f"Result of test case 3 : {sol.reorderedPowerOf2(128)}") # True
