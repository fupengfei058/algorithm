/*给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。*/
class Solution {
public:
    double Power(double base, int exponent) {
    	if(base == 0){
    		return 0;
    	}
    	double flag = 1;
    	if(exponent > 0){
    		for (int i = 0; i < exponent; ++i)
    		{
    			flag *= base;
    		}
    	}
    	if(exponent < 0){
    		for (int i = 0; i < -exponent; ++i)
    		{
    			flag *= (1/base);
    		}
    	}
    	else{
    		return flag;
    	}
    	return flag;
    }
};