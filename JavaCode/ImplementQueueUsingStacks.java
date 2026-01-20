import java.util.Stack;

class MyQueue {
    private Stack<Integer> enqueue;
    private Stack<Integer> diqueue;

    public MyQueue() {
        enqueue = new Stack<>();
	diqueue = new Stack<>();
    }
    
    public void push(int x) {
        enqueue.push(x);
    }
    
    public int pop() {
        shiftStacks();
	return diqueue.pop();
    }
    
    public int peek() {
        shiftStacks();
	return diqueue.peek();
    }
    
    public boolean empty() {
        return enqueue.isEmpty() && diqueue.isEmpty();
    }

    private void shiftStacks() {
	if (diqueue.isEmpty()) {
		while (!enqueue.isEmpty()) {
			diqueue.push(enqueue.pop());
		}
	}
    }
}

public class ImplementQueueUsingStacks {
   public static void main(String[] args) {
	MyQueue obj = new MyQueue();
        
        obj.push(1);
        obj.push(2);
        
        System.out.println("Peek: " + obj.peek());   // Returns 1
        System.out.println("Pop: " + obj.pop());     // Returns 1
        System.out.println("Empty: " + obj.empty()); // Returns false
        
        obj.push(3);
        System.out.println("Pop: " + obj.pop());     // Returns 2
        System.out.println("Pop: " + obj.pop());     // Returns 3
        System.out.println("Empty: " + obj.empty()); // Returns true
   }
}
