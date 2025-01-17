class Solution:
    def doesValidArrayExist(self, derived):
        n = len(derived)

        def is_valid(start):
            original = [start] 
            for i in range(n - 1):
                original.append(original[-1] ^ derived[i])  
            return original[-1] ^ derived[-1] == original[0]  

        return is_valid(0) or is_valid(1)

# Test cases
if __name__ == "__main__":
    solution = Solution()

    # case 1
    derived1 = [1, 1, 0]
    print(solution.doesValidArrayExist(derived1))  # Expected Output: True

    # case 2
    derived2 = [1, 1]
    print(solution.doesValidArrayExist(derived2))  # Expected Output: True

    # case 3
    derived3 = [1, 0]
    print(solution.doesValidArrayExist(derived3))  # Expected Output: False
