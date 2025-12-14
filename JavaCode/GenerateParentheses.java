package JavaCode;

import java.util.ArrayList;
import java.util.List;

// Test cases
public class GenerateParentheses {
    public static void main(String[] args) {
        Solution obj = new Solution();

	// case 1
	int n1 = 3;
	System.out.println("Result of test case 1 : " + obj.generateParenthesis(n1)); // Expected: "((()))","(()())","(())()","()(())","()()()"
	
	// case 2
	int n2 = 1;
	System.out.println("Result of test case 2 : " + obj.generateParenthesis(n2)); // Expected: "()"
    }
}

class Solution {
    public List<String> generateParenthesis(int n) {
        List<String> result = new ArrayList<>();
        backtrack(result, new StringBuilder(), 0, 0, n);
        return result;
    }

    private void backtrack(List<String> result, StringBuilder current, int openCount, int closeCount, int maxPairs) {
        if (current.length() == maxPairs * 2) {
            result.add(current.toString());
            return;
        }

        if (openCount < maxPairs) {
            current.append('(');
            backtrack(result, current, openCount + 1, closeCount, maxPairs);
            current.deleteCharAt(current.length() - 1);
        }

        if (closeCount < openCount) {
            current.append(')');
            backtrack(result, current, openCount, closeCount + 1, maxPairs);
            current.deleteCharAt(current.length() - 1);
        }
    }
}
