/*数组_荷兰国旗问题
设有一个仅由红白蓝(对应0,1,2)三种颜色的条块组成的条块序列。求一种时间复杂度O(n)的算法，使得这些条块按红、白、蓝的顺序排好，即排成荷兰国旗的图案。
思路:快速排序的partition的过程
（1）若遍历到的位置为1，则说明它一定属于中部，根据总思路，中部的我们都不动，然后current向前移动一个位置。
（2）若遍历到的位置为0，则说明它一定属于前部，于是就和begin位置进行交换，然后current向前移动一个位置，begin也向前移动一个位置（表示前边的已经都排好了）。
（3）若遍历到的位置为2，则说明它一定属于后部，于是就和end位置进行交换，由于交换完毕后current指向的可能是属于前部的，
	 若此时current前进则会导致该位置不能被交换到前部，所以此时current不前进。而同1），end向前移动一个位置。*/
#include <iostream>
using namespace std;
void Holland(int*a ,int length) {
	int begin = 0;
	int current = 0;
	int end = length-1;
	while(current <= end)
	{
		if(a[current] == 2)
		{
			swap(a[end],a[current]);
			end--;
		}
		else if(a[current] == 1)
		{
			current++;
		}
		else
		{
			if(begin == current)
			{
				begin++;
				current++;
			}
			else
			{
				swap(a[current],a[begin]);
				// current++;
				begin++;
			}
		}
	}
}