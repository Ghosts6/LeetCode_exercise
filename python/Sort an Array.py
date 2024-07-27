class Solution:
    def sortArray(self, nums):
        if len(nums) <= 1:
            return nums
        return self.mergeSort(nums)
    
    def mergeSort(self, nums):
        if len(nums) <= 1:
            return nums
        mid = len(nums) // 2
        left = self.mergeSort(nums[:mid])
        right = self.mergeSort(nums[mid:])
        return self.merge(left, right)
    
    def merge(self, left, right):
        sorted_array = []
        i = 0
        j = 0
        while i < len(left) and j < len(right):
            if left[i] <= right[j]:
                sorted_array.append(left[i])
                i += 1
            else:
                sorted_array.append(right[j])
                j += 1
        while i < len(left):
            sorted_array.append(left[i])
            i += 1
        while j < len(right):
            sorted_array.append(right[j])
            j += 1
        return sorted_array

# Test case
if __name__ == "__main__":
    solution = Solution()
    nums = [5, 2, 3, 1, 7, 4, 6, 10, 9, 8]
    sorted_nums = solution.sortArray(nums)
    print("Sorted array:", sorted_nums)


