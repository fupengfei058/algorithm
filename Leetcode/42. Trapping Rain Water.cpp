/*Trapping Rain Water:Given n non-negative integers representing an elevation map where the width of each bar is 1, 
compute how much water it is able to trap after raining.*/
class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size() < 3) return 0;
        int left = 0;
        int right = height.size() - 1;
        int sum = 0;
        // 找到左边的第一个峰值
        while(left < right && height[left] <= height[left+1]) left++;
        // 找到右边的第一个峰值
        while(left < right && height[right] <= height[right-1]) right--;
        while(left < right){
            int leftVal = height[left];
            int rightVal = height[right];
            // 如果左边峰值较小，先计算左边
            if(leftVal < rightVal){
                while(left < right && leftVal >= height[++left]){
                    sum += leftVal - height[left];
                }
            // 如果右边峰值较小，先计算右边
            } else {
                while(left < right && rightVal >= height[--right]){
                    sum += rightVal - height[right];
                }
            }
        }
        return sum;
    }
};