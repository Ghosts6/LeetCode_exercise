public class VowelsGameInaString {
    public static void main(String[] args) {
        // Test cases
        Solution sol = new Solution();

        // case 1
        String s1 = "leetcoder";
        System.out.println("Result of test case 1 : " + sol.doesAliceWin(s1)); // Expected true

        // case 2
        String s2 = "bbcd";
        System.out.println("Result of test case 2 : " + sol.doesAliceWin(s2)); // Expected false
    }
}

class Solution {
    public boolean doesAliceWin(String s) {
        for (char c : s.toCharArray()) {
            if (isVowel(c)) {
                return true;
            }
        }
        return false; 
    }

    private boolean isVowel(char c) {
        return "aeiou".indexOf(c) != -1;
    }
}

