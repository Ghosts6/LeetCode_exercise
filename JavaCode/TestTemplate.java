package JavaCode;

import java.util.Arrays;
import java.util.List;

public class TestTemplate {
    public static void main(String[] args) {
        FindWordsContainingCharacter solver = new FindWordsContainingCharacter();

        // Test: findWordsContaining
        // case 1
        String[] example1 = {"leet", "code"};
        char x1 = 'e';
        System.out.println("findWordsContaining example 1: " + solver.findWordsContaining(example1, x1)); // [0, 1]

        // case 2
        String[] example2 = {"abc", "bcd", "aaaa", "cbc"};
        char x2 = 'a';
        System.out.println("findWordsContaining example 2: " + solver.findWordsContaining(example2, x2)); // [0, 2]

        // case 3
        String[] example3 = {"abc", "bcd", "aaaa", "cbc"};
        char x3 = 'z';
        System.out.println("findWordsContaining example 3: " + solver.findWordsContaining(example3, x3)); // []
    }
}

