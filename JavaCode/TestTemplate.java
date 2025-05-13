package JavaCode;

public class TestTemplate {
    public static void main(String[] args) {
        RomanToInteger converter = new RomanToInteger();

        String s1 = "III";
        System.out.println("Input: " + s1 + " | Output: " + converter.romanToInt(s1)); // Output: 3

        String s2 = "LVIII";
        System.out.println("Input: " + s2 + " | Output: " + converter.romanToInt(s2)); // Output: 58

        String s3 = "MCMXCIV";
        System.out.println("Input: " + s3 + " | Output: " + converter.romanToInt(s3)); // Output: 1994
    }
}
