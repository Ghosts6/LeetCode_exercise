package JavaCode;

import java.util.Arrays;

public class TestTemplate {
    public static void main(String[] args) {
        FindLuckyIntegerInAnArray finder = new FindLuckyIntegerInAnArray();
	// case 1
        int[] arr1 = {2, 2, 3, 4};
        System.out.println(finder.findLucky(arr1)); // Output: 2
	// case 2
        int[] arr2 = {1, 2, 2, 3, 3, 3};
        System.out.println(finder.findLucky(arr2)); // Output: 3
	// case 3
        int[] arr3 = {2, 2, 2, 3, 3};
        System.out.println(finder.findLucky(arr3)); // Output: -1
    }
}

