/*一幅扑克牌，任意抽取5张，判断是5张牌是否是顺子。“顺子”指的是五张牌的紧紧相连的五张牌，如A,2,3,4,5或者8,9,10,J,Q，其中，大小王可以代表任意你想代表的牌。
设计一个程序判断随机抽取的5张牌是否是顺子。*/
class Solution {
public:
    bool IsContinuous( vector<int> numbers ) {
        if(numbers.size() != 5)
            return false;
        sort(numbers.begin(),numbers.end());
        int numOfZero=0; //大小王的数量
        int i;
        for(i=0; i<numbers.size(); i++)
        {
            if(numbers[i] == 0)
                numOfZero++;
        }
        int gap=0;
        for(i=numOfZero; i<numbers.size()-1; i++)
        {
            if(!Diff(numbers[i],numbers[i+1]))
                return false;
            gap += numbers[i+1] - numbers[i] -1;
        }
        return ( gap > numOfZero ) ? false : true;
    }
    int Diff(int left,int right)
    {
        return (right-left);
    }
};