//利用两个栈来实现
class Queue {
public:
  stack<int> stackIn,stackOut;
  // Push element x to the back of queue.
  void push(int x) {
      stackIn.push(x);
  }

  // Removes the element from in front of queue.
  void pop(void) {
      if(stackOut.empty()){
          while(!stackIn.empty()){
              stackOut.push(stackIn.top());
              stackIn.pop();
          }
      }
      stackOut.pop();
  }

  // Get the front element.
  int peek(void) {
      if(stackOut.empty()){
          while(!stackIn.empty()){
              stackOut.push(stackIn.top());
              stackIn.pop();
          }
      }
      return stackOut.top();
  }

  // Return whether the queue is empty.
  bool empty(void) {
      return stackIn.empty()&&stackOut.empty();
  }
};
