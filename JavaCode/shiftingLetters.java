package JavaCode;

public class shiftingLetters {
    public String shiftingLetters(String s, int[] shifts) {
        int n = s.length();
        long totalShift = 0;
        char[] chars = s.toCharArray();

        for (int i = n - 1; i >= 0; --i) {
            totalShift = (totalShift + shifts[i]) % 26;
            chars[i] = (char) ((chars[i] - 'a' + totalShift) % 26 + 'a');
        }

        return new String(chars);
    }
}

