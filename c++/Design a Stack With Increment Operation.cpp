#include <iostream>
#include <vector>

class CustomStack {
private:
    std::vector<int> stack;  
    std::vector<int> incrementBuffer; 
    int maxSize; 

public:
    CustomStack(int maxSize) {
        this->maxSize = maxSize;
        incrementBuffer.resize(maxSize, 0); 
    }

    void push(int x) {
        if (stack.size() < maxSize) {
            stack.push_back(x);  
        }
    }

    int pop() {
        if (stack.empty()) {
            return -1;  
        }

        int idx = stack.size() - 1;
        int result = stack[idx] + incrementBuffer[idx]; 

        if (idx > 0) {
            incrementBuffer[idx - 1] += incrementBuffer[idx];  
        }

        incrementBuffer[idx] = 0;  
        stack.pop_back();  

        return result;
    }

    void increment(int k, int val) {
        int limit = std::min(k, (int)stack.size());  
        if (limit > 0) {
            incrementBuffer[limit - 1] += val; 
        }
    }
};
// Test case
int main() {
    CustomStack stk(3); 

    stk.push(1);        
    stk.push(2);       
    std::cout << stk.pop() << std::endl;  

    stk.push(2);   
    stk.push(3);       
    stk.push(4);    

    stk.increment(5, 100);  
    stk.increment(2, 100); 

    std::cout << stk.pop() << std::endl;  
    std::cout << stk.pop() << std::endl;  
    std::cout << stk.pop() << std::endl;  
    std::cout << stk.pop() << std::endl;  
    return 0;
}
