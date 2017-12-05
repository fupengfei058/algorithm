/*图_单词变换问题word-ladder*/
/*Given two words (start and end), and a dictionary, find the length of shortest transformation sequence from start to end
原题连接:https://leetcode.com/problems/word-ladder/
思路:隐式图 广度优先搜索 不需要事先建立图本身*/
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <set>
using namespace std;
class Solution {
public:
    //找cur可以扩展的孩子节点存于children
    void extend(string &cur,string &end,set<string> &dict,vector<string> &children,set<string> &visit)
    { 
        string child = cur;
        children.clear();
        char c,t;
        for(int i=0;i<(int)cur.size();i++)
        {
            t = child[i];
            for(c='a';c!='z';c++)
            {
                if(c==t) continue;
                child[i] = c;
                if(( child==end||( dict.find(child)!=dict.end() ))
                   &&visit.find(child)==visit.end())
                {
                   children.push_back(child);
                   visit.insert(child); 
                }
            } 
            child[i] = t;
        }
       
    }
    int ladderLength(string start, string end, set<string> &dict) {
        //隐式图 广度优先搜索 不需要事先建立图本身  
        if(start==end) return 0;
        queue<string> q;
        q.push(start);
        vector<string> children;//从当前结点可以扩展的新结点集合
        set<string> visit;
        string cur;
        int step = 0;
        int curNumber = 1,nextNumber=0;//当前层还有结点数  下一层的结点数
        while(!q.empty())
        {
            cur = q.front();//从cur开始扩展
            q.pop();
            curNumber--;
            extend(cur,end,dict,children,visit);//结点扩展
            nextNumber+=(int)children.size();
            if(curNumber==0)//当前层遍历完，进入下一层
            {
                step++;
                curNumber = nextNumber;
                nextNumber = 0;
            }
            for(vector<string>::iterator it=children.begin();it!=children.end();++it)
            {
                if(*it==end)
                {
                    return step;
                }
                q.push(*it);
            }
        }
       return 0;
    }
};