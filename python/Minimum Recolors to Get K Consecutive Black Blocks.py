class Solution:
    def minimumRecolors(self, blocks: str, k: int) -> int:
        """
        Returns the minimum number of recolors needed to get k consecutive black blocks
        Approach:
        - Count the number of white blocks in the first k blocks
        - Iterate through the blocks from k to the end
            - If the block at i - k is white, decrement the count of white blocks
            - If the block at i is white, increment the count of white blocks
            - Update the minimum number of operations needed
        - Return the minimum number of operations needed
        """
        min_ops = float('inf')
        count_w = sum(1 for i in range(k) if blocks[i] == 'W')

        min_ops = min(min_ops, count_w)

        for i in range(k, len(blocks)):
            if blocks[i - k] == 'W':
                count_w -= 1
            if blocks[i] == 'W':
                count_w += 1
            min_ops = min(min_ops, count_w)

        return min_ops
    
# Test cases
if __name__ == "__main__":
    solution = Solution()
    # case 1
    blocks_1 = "WBBWWBBWBW"
    k_1 = 7
    print(f"Case 1: {solution.minimumRecolors(blocks_1, k_1)}") # Expected output: 3
    # case 2
    blocks_2 = "WBWBBBW"
    k_2 = 2
    print(f"Case 2: {solution.minimumRecolors(blocks_2, k_2)}") # Expected output: 0