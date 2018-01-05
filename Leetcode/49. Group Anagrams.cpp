/*Group Anagrams:Given an array of strings, group anagrams together.*/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> mp;
        vector<vector<string>> result;
        for(auto str: strs)
        {
            string tem = str;
            sort(tem.begin(), tem.end());
            mp[tem].push_back(str);
        }
        for(auto val: mp)
        {
            sort(val.second.begin(), val.second.end());
            result.push_back(val.second);
        }
        return result;
    }
};