/*双栈排序：请编写一个程序，按升序对栈进行排序（即最大元素位于栈顶），要求最多只能使用一个额外的栈存放临时数据，但不得将元素复制到别的数据结构中。*/
/*思路：把numbers中的一个个元素拿出比较，放入临时栈help中，如果新的元素比help中的小， 便把help中大的取出放入numbers中，压入小的进help,
再把大的从numbers取出压入help。最后把help全部元素放入numbers,返回numbers。*/
#include<iostream>
#include<vector>
using namespace std;
class TwoStacks {
public:
	vector<int> twoStacksSort(vector<int> numbers) {
		vector<int> help;
		while(!numbers.empty()){
			if(help.empty()){
				help.push_back(numbers.back());
				numbers.pop_back();
			}else{
				int temp = numbers.back();
                numbers.pop_back();
                while(!help.empty()&&help.back()>temp){
                   numbers.push_back(help.back());
                   help.pop_back();
                }
                help.push_back(temp);
			}
		}
		while(!help.empty()){
            numbers.push_back(help.back());
            help.pop_back();
        }
        return numbers;
	}
};