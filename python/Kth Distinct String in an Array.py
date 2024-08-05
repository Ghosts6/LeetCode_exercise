class Solution:
    def kthDistinct(self, arr, k):
        freq = {}
        for s in arr:
            if s in freq:
                freq[s] += 1
            else:
                freq[s] = 1

        distinct_strings = [s for s in arr if freq[s] == 1]

        if k <= len(distinct_strings):
            return distinct_strings[k-1]
        else:
            return ""

# Test cases
if __name__ == "__main__":
    sol = Solution()

    arr1 = ["a", "b", "a", "c", "b", "d"]
    k1 = 2
    print(sol.kthDistinct(arr1, k1))  

    arr2 = ["a", "b", "c", "d", "e"]
    k2 = 3
    print(sol.kthDistinct(arr2, k2))  

