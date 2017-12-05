/*请实现一个算法，在不使用额外数据结构和储存空间的情况下，翻转一个给定的字符串(可以使用单个过程变量)。*/
class Reverse {
public:
    string reverseString(string iniString) {
        int len = iniString.size();
        int i = 0;
        int temp;
        for(;i<len/2;i++){
            temp = iniString[len-i-1];
            iniString[len-i-1] = iniString[i];
            iniString[i] = temp;
        }
        return iniString;
    }
};