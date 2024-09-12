#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> splitWordsBySeparator(vector<string>& words, char separator) {
        vector<string> res;
        for(int i = 0 ; i < words.size() ; i++){
            string tmp;
            for(int j = 0 ; j < words[i].size() ; j++){
                if(j == words[i].size() - 1 and words[i][j] != separator){
                    tmp += words[i][j];
                    if(tmp.size()!= 0){
                        res.push_back(tmp);
                    }
                    tmp.clear();
                }else if(words[i][j] == separator){
                    if(tmp.size()!=0){
                        res.push_back(tmp);
                    }
                    tmp.clear();
                }else{
                    tmp += words[i][j];
                }
            }
        }
        return res;
    }
};
int main(){
    return 0;
}