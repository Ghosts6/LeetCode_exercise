from functools import cmp_to_key

class Solution:
    def largestNumber(self, nums):
        nums_str = list(map(str, nums))

        def compare(x, y):
            if x + y > y + x:
                return -1
            elif x + y < y + x:
                return 1
            else:
                return 0
              
        nums_str.sort(key=cmp_to_key(compare))

        result = ''.join(nums_str)

        if result[0] == '0':
            return '0'
        
        return result

# Test cases
sol = Solution()

# case 1
nums1 = [10, 2]
print(sol.largestNumber(nums1))  # Output: "210"

# case 2
nums2 = [3, 30, 34, 5, 9]
print(sol.largestNumber(nums2))  # Output: "9534330"
