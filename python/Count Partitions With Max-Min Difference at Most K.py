class Solution:
    """count partitions with each segment's max-min<=k"""
    def countPartitions(self, nums, k):
        from collections import deque
        MOD = 10**9 + 7
        n = len(nums)
        dp = [0] * (n + 1)
        pre = [0] * (n + 1)
        dp[0] = pre[0] = 1
        minq = deque()
        maxq = deque()
        left = 0
        for i, x in enumerate(nums):
            while minq and nums[minq[-1]] > x:
                minq.pop()
            minq.append(i)
            
            while maxq and nums[maxq[-1]] < x:
                maxq.pop()
            maxq.append(i)
            
            while minq and maxq and nums[maxq[0]] - nums[minq[0]] > k:
                left += 1
                if minq[0] < left:
                    minq.popleft()
                if maxq[0] < left:
                    maxq.popleft()

            if left > 0:
                dp[i + 1] = (pre[i] - pre[left - 1]) % MOD
            else:
                dp[i + 1] = pre[i] % MOD
            
            pre[i + 1] = (pre[i] + dp[i + 1]) % MOD
        
        return dp[n] % MOD

# Test cases
if __name__ == "__main__":
    sol = Solution()

    # case 1
    nums1 = [9, 4, 1, 3, 7] 
    k1 = 4
    print(f"result of test case 1 : {sol.countPartitions(nums1, k1)}") # Expected: 6

    # case 2
    nums2 = [3, 3, 4]
    k2 = 0
    print(f"result of test case 2 : {sol.countPartitions(nums2, k2)}") # Expected: 2
