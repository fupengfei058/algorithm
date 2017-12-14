/*Reverse Integer:Given a 32-bit signed integer, reverse digits of an integer.*/
class Solution {
public:
    int reverse(int x) {
    	const int R = 10;
        if (x == INT_MIN) {
            return 0;
        }
        if (x < 0) {
            return -reverse(-x);
        }
        int64_t res = 0;
        while (x > 0) {
            res = res * R + x % R;
            if (res > INT_MAX) {
                return 0;
            }
            x /= R;
        }
        return res;
    }
};