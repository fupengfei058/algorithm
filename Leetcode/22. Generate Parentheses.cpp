/*Generate Parentheses:Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.*/
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> rs;  
        string s;  
        genParenthesis(rs, s, n, n);  
        return rs;
    }
    void genParenthesis(vector<string> &rs, string &s, int left, int right)
	{
		if (left==0)
		{
			rs.push_back(s);
			rs.back().append(right, ')');
			return;
		}
		s.push_back('(');
		genParenthesis(rs, s, left-1, right);
		s.pop_back();
		if (left < right)
		{
			s.push_back(')');
			genParenthesis(rs, s, left, right-1);
			s.pop_back();
		}
	}
};