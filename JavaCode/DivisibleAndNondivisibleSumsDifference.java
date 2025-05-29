package JavaCode;

public class DivisibleAndNondivisibleSumsDifference {
	public int differenceOfSums(int n, int m) {
        int divisibleSum = 0;
        int nonDivisibleSum = 0;

        for (int i = 1; i <= n; i++) {
            if (i % m == 0) {
                divisibleSum += i;
            } else {
                nonDivisibleSum += i;
            }
        }

        return nonDivisibleSum - divisibleSum;
    }
}
