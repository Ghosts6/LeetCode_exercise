class Solution:
    def minimizeXor(self, num1: int, num2: int) -> int:
        target_set_bits = bin(num2).count('1')
        x = 0

        for i in range(31, -1, -1):
            if target_set_bits > 0 and (num1 & (1 << i)):
                x |= (1 << i)
                target_set_bits -= 1

        for i in range(32):
            if target_set_bits > 0 and not (x & (1 << i)):
                x |= (1 << i)
                target_set_bits -= 1
        
        return x

# Test cases
if __name__ == "__main__":
    sol = Solution()

    # case 1
    num1 = 3
    num2 = 5
    print(f"Inputs: num1 = {num1}, num2 = {num2} \nCase 1 Output: {sol.minimizeXor(num1, num2)}") # Expected Output: 3
    
    # case 2
    num1 = 1
    num2 = 12
    print(f"Inputs: num1 = {num1}, num2 = {num2} \nCase 2 Output: {sol.minimizeXor(num1, num2)}") # Expected Output: 3