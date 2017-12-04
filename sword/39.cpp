/*一个整型数组里除了两个数字之外，其他的数字都出现了两次。请写程序找出这两个只出现一次的数字。*/
class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
    	if(data.size()<2) return;
        int size=data.size();
        int temp=0;
        for(int i=0;i<size;i++)//对数组中每个数字做异或
            temp=temp^data[i];
        if(temp==0) return;
        int index=0;
        while((temp&1)==0)//在整数temp的二进制表示中找到最右边是1的位
        {
            temp=temp>>1;
            ++index;
        }
        //根据数组的倒数第index位是否为1，将数组划分为两个子数组，并分别对两个子数组进行求异或，得到num1和num2  
        *num1=*num2=0;
        for(int i=0;i<size;i++)
        {
            if(IsBit(data[i],index))
                *num1^=data[i];
            else
                *num2^=data[i];
        }
    }
    //判断在num的二进制表示中从右边起的index位是不是1
    bool IsBit(int num,int index)
    {
        num=num>>index;
        return (num&1);
    }
};