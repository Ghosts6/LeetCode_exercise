package JavaCode;
import java.util.Arrays;

public class TestTemplate {
    public static void main(String[] args) {
        SortColors sorter = new SortColors();
	
	// case 1
        int[] nums1 = {2, 0, 2, 1, 1, 0};
        sorter.sortColors(nums1);
        System.out.println("Result of test case 1: " + Arrays.toString(nums1)); // Output: [0, 0, 1, 1, 2, 2]

	// case 2
        int[] nums2 = {2, 0, 1};
        sorter.sortColors(nums2);
        System.out.println("Result of test case 2: " + Arrays.toString(nums2)); // Output: [0, 1, 2]
    }
}
