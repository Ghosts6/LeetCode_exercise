package JavaCode;

import java.util.Arrays;

public class TestTemplate {
    public static void main(String[] args) {
        ValidAnagram solver = new ValidAnagram();
	
	// case 1
        String s1 = "anagram";
        String t1 = "nagaram"; 
        System.out.println("Result of test case 1: " + solver.isAnagram(s1, t1)); // Expected: true

	// case 2
        String s2 = "rat";
        String t2 = "car";
        System.out.println("Result of test case 2: " + solver.isAnagram(s2, t2)); // Expected: false
    }
}

