from collections import Counter

class FindSumPairs:
    def __init__(self, nums1, nums2):
        self.nums1 = nums1
        self.nums2 = nums2
        self.counter2 = Counter(nums2)

    def add(self, index, val):
        old_val = self.nums2[index]
        new_val = old_val + val
        self.counter2[old_val] -= 1
        if self.counter2[old_val] == 0:
            del self.counter2[old_val]
        self.nums2[index] = new_val
        self.counter2[new_val] += 1

    def count(self, tot):
        result = 0
        for num in self.nums1:
            complement = tot - num
            result += self.counter2.get(complement, 0)
        return result

# Test
if __name__ == "__main__":
    findSumPairs = FindSumPairs([1, 1, 2, 2, 2, 3], [1, 4, 5, 2, 5, 4])
  
    print(findSumPairs.count(7))  # Output: 8
    findSumPairs.add(3, 2)
    print(findSumPairs.count(8))  # Output: 2
    print(findSumPairs.count(4))  # Output: 1
    findSumPairs.add(0, 1)
    findSumPairs.add(1, 1)
    print(findSumPairs.count(7))  # Output: 11
