/*Palindrome Number:Determine whether an integer is a palindrome. Do this without extra space.*/
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        int x1 = x;
        int r = 0;
        while (x1 > 0) {
            r = r * 10 + x1 % 10;
            x1 /= 10;
        }
        return r == x;
    }
};