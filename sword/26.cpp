/*输入一个字符串,按字典序打印出该字符串中字符的所有排列。
例如输入字符串abc,则打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。*/
/*输入描述:输入一个字符串,长度不超过9(可能有字符重复),字符只包括大小写字母。*/
class Solution {
public:
	void PermutationHelp(vector<string> &ans, int k, string str) //遍历第k位的所有可能
	{
	    if(k == str.size() - 1)
	        ans.push_back(str);
	    unordered_set<char> us;  //记录出现过的字符
	    sort(str.begin() + k, str.end());  //保证按字典序输出
	    for(int i = k; i < str.size(); i++)
	    {
	        if(us.find(str[i]) == us.end()) //只和没交换过的换
	        {  
	            us.insert(str[i]);
	            swap(str[i], str[k]);
	            PermutationHelp(ans, k + 1, str);
	            swap(str[i], str[k]);  //复位
	        }
	    }
	}
 
	vector<string> Permutation(string str) {
	    vector<string> ans;
	    PermutationHelp(ans, 0, str);
	    return ans;
	}
};