/* 栈_下一个较大元素
现在我们有一个int数组，请你找出数组中每个元素的下一个比它大的元素。 
给定一个int数组A及数组的大小n，请返回一个int数组，代表每个元素比他大的下一个元素,若不存在则为-1。
保证数组中元素均为正整数。
思路: 从后往前维护一个栈,如果当前栈为空则直接入栈,不为空则弹出top，如果top元素大于当前元素则为较大元素;
如果top元素小于当前元素，则继续弹出直到-1或者大于当前元素*/
#include<iostream>
#include<vector>
#include<stack>
using namespace std;
class NextElement {
public:
    vector<int> findNext(vector<int> A, int n) {
    	//从后往前维护一个栈
        stack<int> stack;
        vector<int> result;
        stack.push(-1);//最右边第一个没有下一个较大元素
        //如果当前栈为空则直接入栈
        //不为空则弹出top，如果top元素大于当前元素则为较大元素
        //如果top元素小于当前元素，则继续弹出直到-1或者大于当前元素
        for(int i = n-1; i >= 0; --i)
        {
            int top = stack.top();
            while(top != -1 && A[i] >= top)
            {
                stack.pop();
                top = stack.top();
            }
            result.insert(result.begin(),top);
            stack.push(A[i]);
        }
        return result;
    }
};