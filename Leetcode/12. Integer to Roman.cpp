/*Integer to Roman:Given an integer, convert it to a roman numeral.*/
class Solution {
public:
    string intToRoman(int num) {
        const string ROMAN_TABLE[4][9] = {
            {"I", "II", "III", "IV", "V", "VI", "VII","VIII","IX"},
            {"X", "XX", "XXX", "XL", "L","LX", "LXX","LXXX", "XC"},
            {"C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},
            {"M", "MM", "MMM",  "", "", "", "", "", ""}
    	};
    	string result;
	    for (int i = 0; num; i++, num /= 10) {
		    if (num % 10) {
			    result = ROMAN_TABLE[i][num % 10 - 1] + result;
		    }
	    }
	    return result;
    }
};