/*假定我们都知道非常高效的算法来检查一个单词是否为其他字符串的子串。
请将这个算法编写成一个函数，给定两个字符串s1和s2，请编写代码检查s2是否为s1旋转而成，要求只能调用一次检查子串的函数。*/
/*思路:s1拼接自己一次当作s3，s2如果是s1旋转来的就必定是s3的子串*/
#include <iostream>
#include <string>
class ReverseEqual {
public:
    bool checkReverseEqual(string s1, string s2) {
    	int size1 = s1.size();
    	int size2 = s2.size();
    	if(size1 == 0 || size2 == 0 || size1 != size2){
    		return false;
    	}
    	string s = s1 + s2;
    	if(s.find(s2) == -1){
    		return false;
    	}
    	return true;
    }
};