package JavaCode;

public class TestTemplate {
    public static void main(String[] args) {
        threeConsecutiveOdds solver = new threeConsecutiveOdds();

        int[] arr1 = {2, 6, 4, 1};
        System.out.println(solver.threeConsecutiveOdds(arr1)); // false

        int[] arr2 = {1, 2, 34, 3, 4, 5, 7, 23, 12};
        System.out.println(solver.threeConsecutiveOdds(arr2)); // true
    }  
}

