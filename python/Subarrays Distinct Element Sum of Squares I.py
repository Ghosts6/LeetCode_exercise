from typing import List


class Solution:
    def sumCounts(self, nums: List[int]) -> int:
        n = len(nums)
        if n == 0:
            return 0

        size = 4 * n
        sm = [0] * size
        sq = [0] * size
        lz = [0] * size

        def apply(node: int, l: int, r: int, d: int) -> None:
            length = r - l + 1
            sq[node] += 2 * d * sm[node] + d * d * length
            sm[node] += d * length
            lz[node] += d

        def push(node: int, l: int, m: int, r: int) -> None:
            if lz[node]:
                apply(2 * node, l, m, lz[node])
                apply(2 * node + 1, m + 1, r, lz[node])
                lz[node] = 0

        def update(node: int, l: int, r: int, ql: int, qr: int) -> None:
            if qr < l or r < ql:
                return
            if ql <= l and r <= qr:
                apply(node, l, r, 1)
                return
            m = (l + r) // 2
            push(node, l, m, r)
            update(2 * node, l, m, ql, qr)
            update(2 * node + 1, m + 1, r, ql, qr)
            sm[node] = sm[2 * node] + sm[2 * node + 1]
            sq[node] = sq[2 * node] + sq[2 * node + 1]

        result = 0
        last = {}

        for r in range(n):
            val = nums[r]
            prev = last.get(val, -1)
            update(1, 0, n - 1, prev + 1, r)
            result += sq[1]
            last[val] = r

        return result


if __name__ == "__main__":
    solution = Solution()

    nums1 = [1, 2, 1]
    print("Result of test case 1 :", solution.sumCounts(nums1))

    nums2 = [1, 1]
    print("Result of test case 2 :", solution.sumCounts(nums2))
