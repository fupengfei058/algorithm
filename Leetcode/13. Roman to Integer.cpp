/*Roman to Integer:Given a roman numeral, convert it to an integer.*/
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> ROMAN_TABLE = {
			{'I', 1},
			{'V', 5},
			{'X', 10},
			{'L', 50},
			{'C', 100},
			{'D', 500},
			{'M', 1000}
		};
		int pre = ROMAN_TABLE[s[0]];
		int sum = pre;
		for (int i = 1; i < s.size(); ++i) {
			int cur = ROMAN_TABLE[s[i]];
			sum += cur;
			if (cur > pre) {
				sum -= 2 * pre; // 原来是＋，需要转化为－，因此减去两倍
			}
			pre = cur;
		}
		return sum;
    }
};