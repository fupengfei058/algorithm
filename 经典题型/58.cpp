/*查找和排序_数组中的逆序对
有一组数，对于其中任意两个数组，若前面一个大于后面一个数字，则这两个数字组成一个逆序对。请设计一个高效的算法，计算给定数组中的逆序对个数。
思路：归并排序的思想*/
#include <iostream>
#include <vector>
using namespace std;
class AntiOrder {
public:
    void merge(vector<int>& A, int begin,int mid,int end,int& num)
    {
        
        int i = begin;
        int j = mid+1;
        int size = 0;  
        vector<int> temp(A);
        for(;(i<=mid)&&(j<=end);size++)
        {
            if(A[i]<A[j])
            {
                temp[size] = A[i++];
            }
            else
            {
                num+=mid-i+1;
                temp[size] = A[j++];
            }
       }
       while(i<=mid)
       {
           temp[size++] = A[i++];
       }
       while(j<=end)
       {
           temp[size++] = A[j++];
       }
       for(int i=0;i<size;i++)
       {
           A[begin+i] = temp[i];
       }
    }
    void mergesort(vector<int>& A, int begin,int end,int& num)
    {
        if(begin>=end) return;
        int mid = (begin+end)/2;
        mergesort(A,begin,mid,num);
        mergesort(A,mid+1,end,num);
        merge(A,begin,mid,end,num);
    }
    int count(vector<int> A, int n)
    {
        int num;
        mergesort(A,0,n-1,num);
        return num;
    }
};