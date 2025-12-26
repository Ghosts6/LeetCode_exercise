class Solution:
    def bestClosingTime(self, customers: str) -> int:
        """Return the earliest hour to close the shop with minimum penalty."""
        cur_penalty = max_penalty = best_hour = 0
        
        for i, char in enumerate(customers):
            # If 'Y', penalty decreases by staying open; if 'N', it increases.
            if char == 'Y':
                cur_penalty += 1
            else:
                cur_penalty -= 1
            
            # If current relative penalty is better than our max, update best hour.
            if cur_penalty > max_penalty:
                max_penalty = cur_penalty
                best_hour = i + 1
                
        return best_hour

# Test cases
if __name__ == "__main__":
    sol = Solution()

    # case 1
    customers1 = "YYNY"
    print(f"Result of test case 1 : {sol.bestClosingTime(customers1)}") # Expected 2

    # case 2
    customers2 = "NNNNN"
    print(f"Result of test case 2 : {sol.bestClosingTime(customers2)}") # Expected 0

    # case 3
    customers3 = "YYYY"
    print(f"Result of test case 3 : {sol.bestClosingTime(customers3)}") # Expected 4
