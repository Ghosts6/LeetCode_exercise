#include <iostream>

// O(logn)
class Solution {
public:
       bool checkPerfectNumber(int num) {
           if (num <= 1) return false;
           int divSum = 1;

	   for(int i = 2; i < num / i; i++) {
              if ( num % i == 0) {
                  divSum += i;

		  if (i != num / i) {
  	              divSum += num / i;
	          }
	      } 
	   }

	   return divSum == num;
       }	       
};

/* O(n)
class Solution {
public:
       bool checkPerfectNumber(int num) {
           if (num <= 0 || num % 2 != 0) return false;
           int divSum = 0;

	   for(int i = 1; i < num; i++) {
              if ( num % i == 0) {
                  divSum += i;
	      } 
	   }

	   return divSum == num;
       }	       
};
*/

// Test cases
int main() {
    Solution sol;

    // case 1
    int num1 = 28;
    std::cout<< "Result of test case 1 : " << sol.checkPerfectNumber(num1) << std::endl; // Exepected: true

    // case 2
    int num2 = 7;
    std::cout<< "Result of test case 2 : " << sol.checkPerfectNumber(num2) << std::endl; // Expected: false

    return 0;
}
