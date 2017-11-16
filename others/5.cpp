/*利用字符重复出现的次数，编写一个方法，实现基本的字符串压缩功能。
比如，字符串“aabcccccaaa”经压缩会变成“a2b1c5a3”。若压缩后的字符串没有变短，则返回原先的字符串。*/
/*思路:定义一个字符串数组用来放存在的字符和相应字符的数量*/

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Zipper {
public:
    string zipString(string iniString) 
	{
        // write code here
        int count = 1;
        string newIniString;
        for(int i=0;i<iniString.size();i++)
		{
            while(iniString[i]==iniString[i+1] && (i+1)<iniString.size())
			{
				count++; 
				i++;
            }
            newIniString+=iniString[i];
            newIniString+=intToStr(count);
			count = 1;
        }

        if(newIniString.size()>iniString.size())
		{
            return iniString;
        }
        return newIniString;
    }

   string intToStr(int &i)
   {
      string s;
	  stringstream ss(s);
	  ss << i;
	  return ss.str();
   }
};

int main()
{
  Zipper demo;
  string str;
  str = demo.zipString("aabcccaaa");
  cout<<str<<endl;
  return 0;
}

