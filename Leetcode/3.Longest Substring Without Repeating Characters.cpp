/*Longest Substring Without Repeating Characters:Given a string, find the length of the longest substring without repeating characters.*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i,j;
	    int maxlen = 0;
	    int n = s.size();
	    int arr[256] = {0}; //设置hash表，索引为字符的值，值为是否存在该字符
	    for(i = 0,j = 0;j < n;j++){
	        while(arr[s[j]] == 1){
	            arr[s[i]] = 0;
	            ++i;
	        }
	        arr[s[j]] = 1;
	        maxlen = maxlen > (j-i) ? maxlen : j-i+1;
	    }

	    return maxlen;
    }
};