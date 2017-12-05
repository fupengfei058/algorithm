/*统计一个数字在排序数组中出现的次数。*/
class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        int lower = getLower(data, k);
        int higher = getHigher(data, k);
        //没有k的情况
        if(higher >= data.size() || lower ==  -1) return 0;
        return higher - lower + 1;
    }
    //获取k第一次出现的下标
    int getLower(vector<int>& data, int k){
        int mid, left = 0, right = data.size() - 1;      
        while(left <= right){
            mid = left + ((right - left) >> 1);
            if(data[mid] < k)   left = mid + 1;
            else right = mid - 1;
        }
        return left;
    }
    //获取k最后一次出现的下标
    int getHigher(vector<int>& data, int k){
        int mid, left = 0, right = data.size() - 1;
        while(left <= right){
            mid = left + ((right - left) >> 1);
            if(data[mid] <= k)  left = mid + 1;
            else right = mid - 1;
        }
        return right;
    }
};