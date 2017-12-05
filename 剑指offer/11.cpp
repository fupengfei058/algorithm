/*输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示。*/
class Solution {
public:
     int  NumberOf1(int n) {
     	 int count = 0;
         if (n == 0)
         {
         	return count;
         }
         while(n != 0){
         	++count;
         	n = (n - 1) & n;
         }
         return count;
     }
};