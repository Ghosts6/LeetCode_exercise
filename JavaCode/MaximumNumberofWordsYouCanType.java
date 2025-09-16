public class MaximumNumberofWordsYouCanType {
    public static void main(String[] args) {
        Solution sol = new Solution();

        // case 1
        String text1 = "hello world";
        String brokenLetters1 = "ad";
        System.out.println("Result of test case 1 : " + sol.canBeTypedWords(text1, brokenLetters1)); // Expected 1

        // case 2
        String text2 = "leet code";
        String brokenLetters2 = "lt";
        System.out.println("Result of test case 2 : " + sol.canBeTypedWords(text2, brokenLetters2)); // Expected 1

        // case 3
        String text3 = "leet code";
        String brokenLetters3 = "e";
        System.out.println("Result of test case 3 : " + sol.canBeTypedWords(text3, brokenLetters3)); // Expected 0
    }
}

class Solution {
    public int canBeTypedWords(String text, String brokenLetters) {
        boolean[] broken = new boolean[26];
        for (char c : brokenLetters.toCharArray()) {
            broken[c - 'a'] = true;
        }

        int count = 0;
        boolean valid = true;

        for (int i = 0; i <= text.length(); i++) {
            char c = (i == text.length()) ? '\0' : text.charAt(i);

            if (c == ' ' || c == '\0') {
                if (valid) count++;
                valid = true; 
                if (c == '\0') break;
            } else {
                if (broken[c - 'a']) valid = false;
            }
        }

        return count;
    }
}

