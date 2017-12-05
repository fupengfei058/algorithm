/*字符串_把一个数字看成字符串,判断是否为回文数
示例：
12321 -> true
3 -> true 
133434-> false
思路：通过计算得到数字前后对应位的数字*/
bool isPalindromeNumber(long x)
{
   int a = x,h = 1;
   if(a < 0) return false;
   while(a/h >= 10)//防溢出
   {
     h*=10;//将h扩大到与a相同的位数
   }
   while(a > 0)
   {
	   if(a/h != a%10)
	   {
	     return false;
	   }
	   a = (a%h)/10;
	   h = h/100;
   }
   return true;
}