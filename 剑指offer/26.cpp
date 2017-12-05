/*输入一个字符串,按字典序打印出该字符串中字符的所有排列。
例如输入字符串abc,则打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。*/
/*输入描述:输入一个字符串,长度不超过9(可能有字符重复),字符只包括大小写字母。*/
class Solution {
public:
	vector<string> Permutation(string str) {  
        vector<string> result;   //创建字符串数组  
        int len = str.length();  //求出字符串长度，作为参数传递控制循环次数  
        if(!len) return result;  //当输入为空时，直接返回  
		BubbleSort(str,0,len-1);
        Permutations(result, str, 0, len);  
        return result;  
    }
	void Permutations(vector<string>&result, string str,int index, int len){  
		//当索引指向字符串尾部时，将str压入数组     
		if (index == len){//index==len,说明首位置已经是末尾了，这时的递归输入已经只有一个元素了 
		    result.push_back(str);  
		    return;  
		}
		for (int i = index; i < len; ++i) {  
		    if (i!=index && str[i]== str[index]) continue;// 保证当输入多个重复字符时，不会重复计算  
		    swap(str[i],str[index]);//每一次，交换第i个位置和首位置的元素
		    Permutations(result, str, index+1, len);
		}
	}  
	void BubbleSort(string &A,int left,int high){
		int p,i;
		bool flag;
		int N = A.length();
		for(p=N-1; p >= 0; p--){
			flag = false;
			for(i=0; i<p; i++){
				if(A[i]>A[i+1]){
					swap(A[i],A[i+1]);
					flag = true;
				}
			}
			if(flag == false) break;
		}
	}
};