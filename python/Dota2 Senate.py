from collections import deque

class Solution(object):
    def predictPartyVictory(self, senate):
        radiant = deque()
        dire = deque()

        for i, s in enumerate(senate):
            if s == 'R':
                radiant.append(i)
            else:
                dire.append(i)

        n = len(senate)

        while radiant and dire:
            r = radiant.popleft()
            d = dire.popleft()
            
            if r < d:
                radiant.append(r + n)
            else:
                dire.append(d + n)
        
        return "Radiant" if radiant else "Dire"

# Test cases
if __name__ == "__main__":
    solution = Solution()
    test_senate_1 = "RD"
    test_senate_2 = "RDD"
    
    print(solution.predictPartyVictory(test_senate_1))  
    print(solution.predictPartyVictory(test_senate_2))  

