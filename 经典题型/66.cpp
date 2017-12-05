/*数组_未排序数组中累加和为给定值的最长子数组
思路：sum[i]+k = sum[j],则j-(i+1)的长度即为所求，我们利用一个哈希表记录累加和sum[i]最早出现的位置*/
class maxIsSomeValue {
public:
	int maxlen(int arr[], int k,int n){
		map<int, int> m;
		map<int, int>::iterator it;
		m[0] = -1;
		int len = 0;
		int sum = 0;
		for (int i = 0; i < n; i++)
		{
			sum += arr[i];
			it = m.find(sum - k);
			if (it!=m.end()){
				len = max(i-m[sum - k], len);
			}
			if (it == m.end()){
				m[sum] = i;
			}
		}
		return len;
	}
}