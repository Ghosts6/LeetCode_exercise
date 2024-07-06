class Solution:
    def passThePillow(self, n: int, time: int) -> int:
        cycle_time = n - 1
        complete_cycles, remaining_time = divmod(time, cycle_time)

        if complete_cycles % 2 == 0:
            return 1 + remaining_time
        else:
            return n - remaining_time

# test case
sol = Solution()
n = 5
time = 8
print(f"The person holding the pillow after {time} seconds is at index: {sol.passThePillow(n, time)}")
