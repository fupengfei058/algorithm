/*Count and Say:The count-and-say sequence is the sequence of integers with the first five terms as following:
1.     1
2.     11
3.     21
4.     1211
5.     111221
1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth term of the count-and-say sequence.*/
class Solution {
public:
    string countAndSay(int n) {
        string tmp = "1";
        string ans;
        int cnt = 1;
        for(int i = 2;i <= n;i++){
            for(int j = 0;j < tmp.length();j++){
                if(tmp[j] == tmp[j + 1]){
                    cnt++;
                }
                else {  
                    ans += cnt + '0';
                    ans += tmp[j];
                    cnt = 1;
                }
            }
            tmp = ans;
            ans = "";
        }
        return tmp;
    }
};