class Solution:
    def __init__(self):
        self.five_dollar = 0
        self.ten_dollar = 0

    def lemonadeChange(self, bills):
        for bill in bills:
            if bill == 5:
                self.five_dollar += 1
            elif bill == 10:
                if self.five_dollar > 0:
                    self.five_dollar -= 1
                    self.ten_dollar += 1
                else:
                    return False
            elif bill == 20:
                if self.ten_dollar > 0 and self.five_dollar > 0:
                    self.ten_dollar -= 1
                    self.five_dollar -= 1
                elif self.five_dollar >= 3:
                    self.five_dollar -= 3
                else:
                    return False
        return True

# Test Cases
def test_lemonade_stand():
    stand = Solution()

    # Case 1
    bills = [5, 5, 5, 10, 20]
    case_1_status = stand.lemonadeChange(bills) == True

    # Case 2
    bills = [5, 5, 10, 10, 20]
    case_2_status = stand.lemonadeChange(bills) == False
    
    return {
        "Test Case 1": case_1_status,
        "Test Case 2": case_2_status,
    }

test_results = test_lemonade_stand()
print(test_results)
