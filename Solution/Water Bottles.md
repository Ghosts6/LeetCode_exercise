# Water Bottles 📝

## 🤔 Intuition
The problem asks for the total number of water bottles we can drink. We start with a certain number of full water bottles. We can drink them, and they become empty. We can then exchange a certain number of empty bottles for a new full water bottle. This process continues until we can no longer make any exchanges. The core idea is to keep track of the number of bottles we drink and the number of empty bottles we have.

## ⚙️ Approach
1.  **Initial Count:** We start by drinking all the initial bottles, so our count of `totalDrunk` begins at `numBottles`. The number of `emptyBottles` is also `numBottles`.
2.  **Exchange Loop:** We enter a loop that continues as long as we have enough `emptyBottles` to make an exchange (`emptyBottles >= numExchange`).
3.  **Calculate New Bottles:** Inside the loop, we calculate how many `newBottles` we can get by integer dividing `emptyBottles` by `numExchange`.
4.  **Update Drunk Count:** We add these `newBottles` to our `totalDrunk` count.
5.  **Update Empty Bottles:** The number of `emptyBottles` is updated. It becomes the sum of the leftover bottles from the exchange (`emptyBottles % numExchange`) and the `newBottles` we just acquired (which will also become empty).
6.  **Termination:** The loop terminates when we no longer have enough empty bottles to make an exchange.
7.  **Final Result:** The `totalDrunk` variable now holds the maximum number of water bottles we can drink.

---

## 📊 Complexity Analysis
-   **Time Complexity:** $$O(\log_{numExchange}(numBottles))$$
    *   In each iteration of the loop, the number of empty bottles is roughly divided by `numExchange`. The process continues until the number of empty bottles is less than `numExchange`. This is characteristic of a logarithmic time complexity.

-   **Space Complexity:** $$O(1)$$
    *   We only use a few variables to keep track of the counts (`totalDrunk`, `emptyBottles`, `newBottles`). The space required does not scale with the input size, so it is constant.

---

## 💻 Code Implementations

### C
```c
#include <stdio.h>

int numWaterBottles(int numBottles, int numExchange) {
    int totalDrunk = numBottles;
    int emptyBottles = numBottles;

    while (emptyBottles >= numExchange) {
        int newBottles = emptyBottles / numExchange;
        emptyBottles = emptyBottles % numExchange + newBottles;
        totalDrunk += newBottles;
    }

    return totalDrunk;
}
```

### C++
```cpp
#include <iostream>

class Solution {
	public:
	int numWaterBottles(int numBottles, int numExchange) {
    	int totalDrunk = numBottles;
    	int emptyBottles = numBottles;

    	while (emptyBottles >= numExchange) {
        	int newBottles = emptyBottles / numExchange;
        	emptyBottles = emptyBottles % numExchange + newBottles;
        	totalDrunk += newBottles;
    	}

    	return totalDrunk;
	}
};
```

### Python
```python
class Solution:
    def numWaterBottles(self, numBottles: int, numExchange: int) -> int:
        """
        return the maximum number of water bottles you can drink.
        """
        total = numBottles
        empty = numBottles
        while empty >= numExchange:
            new = empty // numExchange
            empty = empty % numExchange + new
            total += new
        return total
```

### Java
```java
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
```
