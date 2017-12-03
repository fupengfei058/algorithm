/*把只包含因子2、3和5的数称作丑数（Ugly Number）。例如6、8都是丑数，但14不是，因为它包含因子7。 
习惯上我们把1当做是第一个丑数。求按从小到大的顺序的第N个丑数。*/
class Solution {
public:
    int GetUglyNumber_Solution(int index) {
    	if(index<=0)
            return 0;
        int a[index];
        a[0]=1;
        int i,j=0,k=0,l=0;
        for(i=1;i<index;i++)
        {
            a[i]=min(min(a[j]*2,a[k]*3),a[l]*5);
            if(a[i]==a[j]*2)
                j++;
            if(a[i]==a[k]*3)
                k++;
            if(a[i]==a[l]*5)
                l++;
        }
        return a[index-1];
    }
};