/*数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。
由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。如果不存在则输出0。*/
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
    	if(numbers.empty()) return 0;
    	int result = numbers[0];
    	int times = 1;
    	for(int i = 0; i < numbers.size(); i++){
    		if(times == 0){
    			result = numbers[i];
    			times = 1;
    		}else if(numbers[i] == result){
    			times++;
    		}else{
    			times--;
    		}
    	}
    	times = 0;
        for(int i=0; i<numbers.size(); ++i){
            if(numbers[i] == result) ++times;
        }
		return (times > numbers.size()/2) ? result : 0;
    }
};