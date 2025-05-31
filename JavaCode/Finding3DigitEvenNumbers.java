package JavaCode;
import java.util.*;

public class Finding3DigitEvenNumbers {
	public int[] findEvenNumbers (int[] digits) {
        Set<Integer> result = new HashSet<>();
        int n = digits.length;

       for (int i = 0; i < n; i++) {
            if (digits[i] == 0) continue; // First digit can't be 0
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                for (int k = 0; k < n; k++) {
                    if (k == i || k == j) continue;

                    int num = digits[i] * 100 + digits[j] * 10 + digits[k];
                    if (num % 2 == 0) { // Check if number is even
                        result.add(num);
                    }
                }
            }
        }

        int[] res = new int[result.size()];
        int index = 0;
        for (int num : result) {
            res[index++] = num;
        }
        Arrays.sort(res);
        return res;
	}
}
