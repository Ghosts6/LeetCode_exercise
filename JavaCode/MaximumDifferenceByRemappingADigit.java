package JavaCode;

public class MaximumDifferenceByRemappingADigit {

    public int minMaxDifference(int num) {
        String str = String.valueOf(num);
        int max = Integer.MIN_VALUE, min = Integer.MAX_VALUE;

        for (char from = '0'; from <= '9'; from++) {
            for (char to = '0'; to <= '9'; to++) {
                String replaced = str.replace(from, to);
                int value = Integer.parseInt(replaced);
                max = Math.max(max, value);
                min = Math.min(min, value);
            }
        }

        return max - min;
    }
}
