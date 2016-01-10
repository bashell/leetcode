// 两个栈模拟队列
class Queue {
public:
    // Push element x to the back of queue.
    void push(int x) {  // 所有push都加入到s1中
        while(!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
        s1.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {  // 所有pop都从s2中操作
        while(!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
        s2.pop();
    }

    // Get the front element.
    int peek(void) {  // peek从s2中操作
        while(!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
        return s2.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return s1.empty() && s2.empty();
    }
private:
    std::stack<int> s1, s2;
};
