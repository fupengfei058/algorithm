/*有一个介于0和1之间的实数，类型为double，返回它的二进制表示。如果该数字无法精确地用32位以内的二进制表示，返回“Error”。*/
#include<iostream>
#include<string>
using namespace std;
class BinDecimal {
public:
    string printBin(double num){
		string res = doubleToBinary(num);
		if(res.length()>32){
		   return "Error";
		}else{
		   return "0."+res;
		}
    }
    string doubleToBinary(double num){
		string str = "";
		if(num*2==0.0)return 0+"";
		if(num*2>1)
		{
		   str = "1"+doubleToBinary(num*2-1);
		}
		else if(num*2==1)
		{
		    return "1";
		}
		else{
		    str = "0"+doubleToBinary(num*2);
		}
		return str;
    }
};