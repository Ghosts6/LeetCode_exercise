from typing import List

class Solution:
    def maxEnvelopes(self, envelopes: List[List[int]]) -> int:
        envelopes.sort(key=lambda x: (x[0], -x[1]))

        heights = [h for _, h in envelopes]

        lis_sequence = []
        for h in heights:
            pos = self.binary_search(lis_sequence, h)
            if pos == len(lis_sequence):
                lis_sequence.append(h)
            else:
                lis_sequence[pos] = h

        return len(lis_sequence)

    def binary_search(self, sequence: List[int], target: int) -> int:
        left, right = 0, len(sequence)
        while left < right:
            mid = left + (right - left) // 2
            if sequence[mid] < target:
                left = mid + 1
            else:
                right = mid
        return left

# Test cases
if __name__ == "__main__":
    solution = Solution()

    # case 1
    envelopes1 = [[5,4], [6,4], [6,7], [2,3]]
    print("Output for envelopes1:", solution.maxEnvelopes(envelopes1))  # Expected output: 3

    # case 2
    envelopes2 = [[1,1], [1,1], [1,1]]
    print("Output for envelopes2:", solution.maxEnvelopes(envelopes2))  # Expected output: 1
