//主要是pop操作比较麻烦，得先迁移到另一个队列，然后把最后的元素删除，再倒回来
class Stack {
public:
    queue<int> inQueue,outQueue;
    // Push element x onto stack.
    void push(int x) {
        inQueue.push(x);
    }

    // Removes the element on top of the stack.
    void pop() {
        if(outQueue.empty()){
            while(inQueue.size()>1){
                outQueue.push(inQueue.front());
                inQueue.pop();
            }
        }
        inQueue.pop();
        while(!outQueue.empty()){
            inQueue.push(outQueue.front());
            outQueue.pop();
        }
    }

    // Get the top element.
    int top() {
        
        return inQueue.back();
    }

    // Return whether the stack is empty.
    bool empty() {
        return inQueue.empty()&&outQueue.empty();
    }
};
