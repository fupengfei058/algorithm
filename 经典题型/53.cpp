/*二叉树_折纸问题
请把纸条竖着放在桌子上，然后从纸条的下边向上方对折，压出折痕后再展开。此时有1条折痕，突起的⽅向指向纸条的背面，这条折痕叫做“下”折痕；
突起的方向指向纸条正面的折痕叫做“上”折痕。如果每次都从下边向上方对折，对折N次。请从上到下计算出所有折痕的方向。
给定折的次数n,请返回从上到下的折痕的数组，若为下折痕则对应元素为"down",若为上折痕则为"up".*/
#include <iostream>
#include <vector>
using namespace std;
class FoldPaper {
public:
    vector<string> foldPaper(int n) {
       vector<string> ret;
       fold(1,n,true,ret);
       return ret;
    }
    void fold(int i,int N,bool down,vector<string> &ret)
    {
        if(i>N) return ;
        fold(i+1,N,true,ret);
        ret.push_back(down?"down":"up");
        fold(i+1,N,false,ret);
    }
};