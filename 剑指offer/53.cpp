/*请实现一个函数用来找出字符流中第一个只出现一次的字符。例如，当从字符流中只读出前两个字符"go"时，第一个只出现一次的字符是"g"。
当从该字符流中读出前六个字符“google"时，第一个只出现一次的字符是"l"。如果当前字符流没有存在出现一次的字符，返回#字符。*/
class Solution
{
public:
	int hashTable[256] = {0}; //建立哈希数组
    string s; 
  //Insert one char from stringstream
    void Insert(char ch)
    {
         if(ch > 256) return;
         s = s+ch; //字符放入字符串中
         hashTable[ch]++; //根据字符，修改哈希数组元素的值
    }
  //return the first appearence once char in current stringstream
    char FirstAppearingOnce()
    {
    	for(char c : s){  //注意的是，要找第一个出现一次的字符，所以遍历字符串，不能遍历哈希数组
            if(hashTable[c] == 1)  //如果字符串作为下标的元素值为1，就说明该字符出现一次，直接返回该字符
                return c;
        }
        return '#';
    }
};