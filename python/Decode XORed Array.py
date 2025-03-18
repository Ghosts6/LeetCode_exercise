from typing import List

class Solution:
    def decode(self, encoded: list[int], first: int) -> list[int]:
        """
        Decodes the original array from the given encoded array.
        """
        arr = [first]
        for num in encoded:
            arr.append(arr[-1] ^ num)
        return arr

# Test cases
if __name__ == "__main__":
    solution = Solution()

    # case 1
    encoded1 = [1,2,3]
    first1 = 1
    print("result for {0} and {1} is : {2}".format(encoded1, first1, solution.decode(encoded1, first1)))# Expected Output: [1,0,2,1]

    # case 2
    encoded2 = [6,2,7,3]
    first2 = 4
    print("result for {0} and {1} is : {2}".format(encoded2, first2, solution.decode(encoded2, first2)))# Expected Output: [4,2,0,7,4]
