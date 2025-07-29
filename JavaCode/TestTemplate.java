package JavaCode;

import java.util.Arrays;

public class TestTemplate {
    public static void main(String[] args) {
        shiftingLetters shifter = new shiftingLetters();

        // case 1
        String s1 = "abc";
        int[] shifts1 = {3, 5, 9};
        System.out.println(shifter.shiftingLetters(s1, shifts1)); // Output: "rpl"

        // case 2
        String s2 = "aaa";
        int[] shifts2 = {1, 2, 3};
        System.out.println(shifter.shiftingLetters(s2, shifts2)); // Output: "gfd"
    }
}
