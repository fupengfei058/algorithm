/*数组_数组中出现次数超过一半的数字
思路：同时删掉两个不同的数，众数不变。 
于是我们随便记录一个数x，来一个数 y，和x不同的话就把x ,y都扔了，相当于扔掉两个不同的数，和x相同的话，就把计数器加1*/
#include<iostream>
using namespace std;
int main()
{
    int m,n;
    cin>>m>>n;
    int time,res;
    for(int i=m*n,time=0;i;--i)
    {
        int a;
        cin>>a;
        if(time==0)
        {
            res = a;
        }
        if(a==res)
        {
            time++;
        }
        else
        {
            time--;
        }
    }
    cout<<res<<endl;
    return 0;
}