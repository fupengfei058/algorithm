/*动态规划和递归_魔术索引
在数组A[0..n-1]中，有所谓的魔术索引，满足条件A[i]=i。给定一个不下降序列，元素值可能相同，编写一个方法，判断在数组A中是否存在魔术索引。
请思考一种复杂度优于o(n)的方法。
思路:事实上，看到A[5]=3时按照二分查找的做法，我们需要递归搜索右半部分。不过，如搜索左半部分， 我们可以跳过一些元素，
值递归搜索A[0]到A[3]的元素。A[3]是第一个可能成为魔术索引的元素。
综上：我们得到一种搜索模式，先比较midIndex和midValue是否相同。然后，若两者不同，则按如下方式递归搜索左半部分和右半部分。 
左半部分：搜索索引从start到min(midIndex-1,midValue)的元素。 
右半部分：搜索索引从max(midIndex+1,minValue)到end的元素。*/
#include <iostream>
#include <vector>
using namespace std;
class MagicIndex {
public:
    bool findMagicIndex(vector<int> A, int n,int start=0,int end =0) {
    	if (start > end || start < 0 || end > n)
        {
            return false;
        }
        int mid = (end - start) / 2 + start;
        if (A[mid] == mid)
        {
            return true;
        }
        else
        {
        	int leftEnd = min(mid - 1, A[mid]);
            int rightStart = max(mid + 1, A[mid]);
            return findMagicIndex(A, n, start, leftEnd) || findMagicIndex(A, n, rightStart, end);
        }
    }
};