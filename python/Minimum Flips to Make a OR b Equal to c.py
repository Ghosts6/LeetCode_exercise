class Solution:
    def minFlips(self, a, b, c):
        flips = 0
        while a > 0 or b > 0 or c > 0:
            bit_a = a & 1
            bit_b = b & 1
            bit_c = c & 1
            
            if bit_c == 1:
                if bit_a == 0 and bit_b == 0:
                    flips += 1

            else:
                flips += bit_a + bit_b

            a >>= 1
            b >>= 1
            c >>= 1

        return flips


if __name__ == "__main__":
    solution = Solution()
    # case 1
    a = 2
    b = 6
    c = 5
    output = solution.minFlips(a, b, c)
    print(f"Input: a = {a}, b = {b}, c = {c} -> Output: {output}")
    
    # case 2
    a = 4
    b = 2
    c = 7
    output = solution.minFlips(a, b, c)
    print(f"Input: a = {a}, b = {b}, c = {c} -> Output: {output}")
    
    #  case 3
    a = 1
    b = 2
    c = 3
    output = solution.minFlips(a, b, c)
    print(f"Input: a = {a}, b = {b}, c = {c} -> Output: {output}")
