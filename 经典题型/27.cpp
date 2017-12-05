/*给定一个整型数组arr，其中有两个数出现了奇数次，其他的数都出现了偶数次，找到这两个数。要求时间复杂度为O(N)，额外空间复杂度为O(1)*/
/*思路:
比如出现奇数次的a,b
定义eO=0遍历arr依次异或，结果为eO=a^b
因为a、b互异，所以eO不等于0，设eO的第k位为1
定义变量eOhasOne = 0;与arr中第k位为1的值进行依次异或，结果eOhasOne = a或eOhasOne =b
通过eO^eOhasOne求得另外一个数*/
#include<iostream>
#include<vector>
using namespace std;
class OddAppearance {
public:
    vector<int> findOdds(vector<int> arr, int n) {
    	int eO = 0, eOhasOne = 0;
        for (int curNum : arr) {
            eO ^= curNum;
        }
        int rightOne = eO & (~eO + 1);//取反后加1变换符号
        for (int cur : arr) {
            if ((cur & rightOne) != 0) {
                eOhasOne ^= cur;
            }
        }
        int small = Math.min(eOhasOne, (eO ^ eOhasOne));
        int big = Math.max(eOhasOne, (eO ^ eOhasOne));
        return new int[] { small, big };
    }
};