from typing import List

class Solution:
    def asteroidCollision(self, asteroids: List[int]) -> List[int]:
        stack = []
        
        for asteroid in asteroids:
            while stack and asteroid < 0 < stack[-1]:
                if stack[-1] < -asteroid:
                    stack.pop()
                    continue
                elif stack[-1] == -asteroid:
                    stack.pop()
                break
            else:
                stack.append(asteroid)
        
        return stack

# test case
if __name__ == "__main__":
    solution = Solution()
    asteroids = [5, 10, -5]
    print(solution.asteroidCollision(asteroids)) 
    
    asteroids = [8, -8]
    print(solution.asteroidCollision(asteroids)) 