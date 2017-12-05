/*压缩字符串的空格 要求时间复杂度O(N)空间复杂度O(1)*/
/*思路: 定义两个游标，如果当前不是空格就把该处的值赋值给前面*/
#include <iostream>
using namespace std;
int removeBlank(char *pString){
	int i = 0, j = 0;
	while(pString[i] != '\0'){
		if(pString[i] != ' '){
			if(i != j){
				pString[j] = pString[i];
			}
			j++;
		}
		i++;
	}
	pString[j] = '\0'; //字符串结束
	return 0;
}

int main(){
	char str[] = "i have a  dream";
	removeBlank(str);
	cout<<str.size()<<endl;
	return 0;
}