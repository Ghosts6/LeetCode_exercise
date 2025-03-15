class Solution:
    def sortEvenOdd(self, nums):
        even = sorted(nums[0::2])
        odd = sorted(nums[1::2], reverse=True)
        
        nums[0::2], nums[1::2] = even, odd
        
        return nums

# class Solution:
#     @staticmethod
#     def bubble_sort(arr, reverse=False):
#         """
#         Sorts the given list in ascending order if reverse is False, otherwise in descending order.
#         """
#         n = len(arr)
#         for i in range(n - 1):
#             for j in range(n - i - 1):
#                 if (arr[j] > arr[j + 1]) != reverse:
#                     arr[j], arr[j + 1] = arr[j + 1], arr[j]

#     def sortEvenOdd(self, nums: list[int]) -> list[int]:
#         """
#         Returns a list of integers where the even indices are sorted in ascending order and the odd indices are sorted in descending order.
#         """
#         even, odd = nums[0::2], nums[1::2]

#         self.bubble_sort(even)
#         self.bubble_sort(odd, reverse=True)

#         nums[0::2], nums[1::2] = even, odd

#         return nums

# Test case
if __name__ == "__main__":
    solution = Solution()

    # case 1
    nums1 = [4, 1, 2, 3]
    print(f"Result for {nums1} : {solution.sortEvenOdd(nums1)}") # Expected Output: 2,3,4,1
    # case 2
    nums2 = [2, 1]
    print(f"Result for {nums2} : {solution.sortEvenOdd(nums2)}") # Expected Output: 1,2
