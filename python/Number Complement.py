class Solution:
    def findComplement(self, num: int) -> int:
        binary_repr = bin(num)[2:]
        
        flipped_bits = ''.join('1' if bit == '0' else '0' for bit in binary_repr)

        complement = int(flipped_bits, 2)
        
        return complement

# Test cases
if __name__ == "__main__":
    test_cases = [
        (5, 2), 
        (1, 0), 
        (10, 5), 
        (0, 1)     
    ]
    
    calculator = Solution()
    for num, expected in test_cases:
        result = calculator.findComplement(num)
        print(f"Complement of {num} is {result}, Expected: {expected}")