package JavaCode;

public class WaterBottles {
	public static void main(String[] args) {
		Solution obj = new Solution();

		// case 1
		int numBottles = 9;
		int numExchange = 3;
		System.out.println("Result of test case 1 : " + obj.numWaterBottles(numBottles, numExchange)); // Expected 13

		// case 2
		int numBottles2 = 15;
		int numExchange2 = 4;
		System.out.println("Result of test case 2 : " + obj.numWaterBottles(numBottles2, numExchange2)); // Expected 19
	}
}

class Solution {
	public int numWaterBottles(int numBottles, int numExchange) {
        int totalDrunk = numBottles;
        int emptyBottles = numBottles;

        while (emptyBottles >= numExchange) {
            int newBottles = emptyBottles / numExchange;
            emptyBottles = emptyBottles % numExchange + newBottles;
            totalDrunk += newBottles;
        }

        return totalDrunk;		
	}
}
