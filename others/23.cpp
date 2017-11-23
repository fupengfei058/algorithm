/*有家动物收容所只收留猫和狗，但有特殊的收养规则，收养人有两种收养方式，第一种为直接收养所有动物中最早进入收容所的，
第二种为选择收养的动物类型（猫或狗），并收养该种动物中最早进入收容所的。 */
/*思路：维护两个队列，一个队列存放放入的狗，一个队列存放放入的猫,每次把动物放入队列的时候，同时将一个递增的序号放入队列，这个序号就是一个时间序列*/
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class CatDogAsylum {
public:
    vector<int> asylum(vector<vector<int> > ope){
    	queue<int> dog;
        queue<int> cat;
        vector<int> vec;//收养的序列
        int index = 0;//用于标记所有动物进入的顺序
        for(int i=0;i<ope.size();i++)
        {
            //表有动物进入收容所
            if(ope[i][0] == 1)
            {
                if(ope[i][1]>=0)
                {
                    //狗
                    dog.push(index++);
                    dog.push(ope[i][1]);
                }
                else{
                    cat.push(index++);
                    cat.push(ope[i][1]);
                }
            }
            else if(ope[i][0] == 2)
            {
                //则代表有人收养动物
                if(ope[i][1] == 0){
                    //直接收养所有动物中最早进入收容所
                     int min=0;
                    if(cat.empty()&&!dog.empty())
                        min=1;
                    if(!cat.empty()&&dog.empty())
                        min=-1;
                    if(!cat.empty()&&!dog.empty())
                        min=dog.front()>cat.front()?-1:1;
                    if(min==-1)
                    {
                        cat.pop();
                        vec.push_back(cat.front());
                        cat.pop();
                    }
                    if(min==1)
                    {
                        dog.pop();
                        vec.push_back(dog.front());
                        dog.pop();
                    }
                }
                else if(ope[i][1] == 1 && !dog.empty())
                {
                    //选择收养狗，并收养该种动物中最早进入收容所的。 
                    dog.pop();
                    vec.push_back(dog.front());
                    dog.pop();
                }
                else if(ope[i][1] == -1 && !cat.empty())
                {
                    //选择收养猫，并收养该种动物中最早进入收容所的。
                       cat.pop();
                       vec.push_back(cat.front());
                       cat.pop();
                }
            }
        }
        return vec;
    }
};