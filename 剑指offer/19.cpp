/*定义栈的数据结构，请在该类型中实现一个能够得到栈最小元素的min函数。*/
class Solution {
public:
    void push(int value) {
        stack1.push(value);
    }
    void pop() {
        stack1.pop();
    }
    int top() {
        return stack1.top();
    }
    int min() {
        int min = 0;
        if(!stack1.empty()){
        	min = stack1.top();
        	stack2.push(min);
        	stack1.pop();
        }
        while(!stack1.empty()){
        	if(min > stack1.top()){
        		min = stack1.top();
        		stack2.push(min);
        		stack1.pop();
        	}else{
        		stack2.push(stack1.top());
        		stack1.pop();
        	}
        }
        while(!stack2.empty()){
        	stack1.push(stack2.top());
        	stack2.pop();
        }
        return min;
    }
private:
	stack<int> stack1;
    stack<int> stack2;
};
