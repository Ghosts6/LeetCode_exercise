package JavaCode;

import java.util.*;

// Test cases
public class CouponCodeValidator {
    public static void main(String[] args) {
	Solution obj = new Solution();

	// case 1
	String[] code = {"SAVE20", "", "PHARMA5", "SAVE@20"};
	String[] businessLine = {"restaurant", "grocery", "pharmacy", "restaurant"};
	boolean[] isActive = {true, true, true, true};
	System.out.println("Result of test case 1 : " + obj.validateCoupons(code, businessLine, isActive)); // Expected: "PHARMA5","SAVE20"
    	
	// case 2
	String[] code2 = {"GROCERY15", "ELECTRONICS_50", "DISCOUNT10"};
        String[] businessLine2 = {"grocery", "electronics", "invalid"};
        boolean[] isActive2 = {false, true, true};
	System.out.println("Result of test case 2 : " + obj.validateCoupons(code2, businessLine2, isActive2)); // Expected: "ELECTRONICS_50"
    }
}

class Solution {
    public List<String> validateCoupons(String[] code, String[] businessLine, boolean[] isActive) {
        Map<String, Integer> order = new HashMap<>();
        order.put("electronics", 0);
        order.put("grocery", 1);
        order.put("pharmacy", 2);
        order.put("restaurant", 3);

        List<String[]> valid = new ArrayList<>();

        for (int i = 0; i < code.length; i++) {
            if (!isActive[i]) continue;
            if (code[i] == null || code[i].isEmpty()) continue;
            if (!code[i].matches("[A-Za-z0-9_]+")) continue;
            if (!order.containsKey(businessLine[i])) continue;
            valid.add(new String[]{businessLine[i], code[i]});
        }

        valid.sort((a, b) -> {
            int c = Integer.compare(order.get(a[0]), order.get(b[0]));
            return c != 0 ? c : a[1].compareTo(b[1]);
        });

        List<String> result = new ArrayList<>();
        for (String[] v : valid) result.add(v[1]);
        return result;
    }
}
