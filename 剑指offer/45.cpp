/*0,1，...n-1这n个数字排成一个圆圈，从数字0开始每次从这个圆圈里删除第m个数字，求出这个圆圈里剩下的最后一个数字。*/
class Solution {
public:
    int LastRemaining_Solution(int n, int m)
    {
        if(n < 1 || m < 1) return -1;
        int last = 0;
        for(int i = 2; i <= n; i++){
            last = (last + m) % i;
        }
        return last;
    }
};