class MinStack {
public:
    /** initialize your data structure here. */
    //利用两个栈，一个保存数据，另一个保存当前栈的最小值
    stack<int> numStack,minStack;
    MinStack() {
        
    }
    
    void push(int x) {
        numStack.push(x);
        if(minStack.empty()){
            minStack.push(x);
            return;
        }
        //如果新加入的值比当前栈最小值小，那么把这个压入最小值栈
        if( x<minStack.top()){
            minStack.push(x);
        }else{
            minStack.push(minStack.top());
        }
    }
    
    void pop() {
        numStack.pop();
        minStack.pop();
    }
    
    int top() {
        return numStack.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};
