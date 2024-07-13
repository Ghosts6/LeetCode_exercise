class Solution:
    def survivedRobotsHealths(self, positions, healths, directions):
        robots = sorted(zip(positions, healths, directions, range(len(positions))))
        
        stack = []
        
        for pos, health, direction, idx in robots:
            if direction == 'R':
                stack.append((pos, health, direction, idx))
            else:  
                while stack and stack[-1][2] == 'R' and health > 0:
                    r_pos, r_health, r_dir, r_idx = stack[-1]
                    if r_health < health:
                        health -= 1
                        stack.pop()
                    elif r_health > health:
                        r_health -= 1
                        health = 0
                        stack[-1] = (r_pos, r_health, r_dir, r_idx)
                    else:
                        stack.pop()
                        health = 0
                
                if health > 0:
                    stack.append((pos, health, direction, idx))
        
        result = sorted(stack, key=lambda x: x[3])
        return [health for pos, health, direction, idx in result]

# Test case
solution = Solution()
positions = [3, 5, 1, 4]
healths = [10, 10, 10, 10]
directions = "RLRL"
print(solution.survivedRobotsHealths(positions, healths, directions))

