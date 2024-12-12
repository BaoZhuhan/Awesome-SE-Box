#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        map<string , int> mp1;
        map<string , int> mp2;
        set<string> st;
        for(auto  i : words1){
            if(mp1.count(i) == 0){
                mp1.insert(make_pair(i,1));
                st.insert(i);
            }else{
                mp1[i]++;
            }
        }
        for(auto i : words2){
            if(mp2.count(i) == 0){
                mp2.insert(make_pair(i,1));
                st.insert(i);
            }else{
                mp2[i]++;
            }
        }
        int ans = 0;
        for(auto i : st){
            if(mp1[i] == 1 and mp2[i] == 1){
                ans++;
            }
        }
        return ans;
    }
};
int main(){
    return 0;
}