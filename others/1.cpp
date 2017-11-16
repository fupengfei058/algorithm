/*请实现一个算法，确定一个字符串的所有字符是否全都不同。这里我们要求不允许使用额外的存储结构。*/
/*思路:基于快速排序的partition，可以边排序边找重复*/

#include <iostream>
using namespace std;

class Different {   
	bool quick_check(string &str,int low,int high)
	{
			int first = low,last = high;

			char key = str[first];

			if (low>=high)

				return true;

			while(first<last){

				while(first <last && str[last] >= key)

					last--;            

				str[first] = str[last];

				while(first<last && str[first] <= key)

					first++;

				str[last] = str[first];

			}

			str[first] = key;

			if (first>low && str[first] == str[first-1])

				return false;

			if (first<high && str[first] == str[first+1])

				return false;

			return quick_check(str,low,first-1) && quick_check(str,first+1,high);
		}

	public:

		bool checkDifferent(string iniString) 
		{
			return quick_check(iniString,0,iniString.size()-1);
		}
};