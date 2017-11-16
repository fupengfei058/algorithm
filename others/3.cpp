/*给定两个字符串，请编写程序，确定其中一个字符串的字符重新排列后，能否变成另一个字符串。这里规定大小写为不同字符，且考虑字符串重点空格。*/

#include <iostream>
#include <string>
using namespace std;

class Same {
public:
    bool checkSam(string stringA, string stringB) {
    if(stringA.size() != stringB.size()){
        return false;
    } 
    int str[256] = {0};

    for(int i = 0; i < stringA.size(); i++){
        str[stringA[i]]++;
        str[stringB[i]]--;
    }

    for(int i = 0;i<256;i++){
        if(str[i]!= 0) return false;
    }
    return true;
}
};