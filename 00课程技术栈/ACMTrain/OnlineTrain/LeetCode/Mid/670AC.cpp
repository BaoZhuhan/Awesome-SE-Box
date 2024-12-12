#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        vector<int> mxp(s.size());
        int p_max = s.size() - 1;
        int p_change = s.size() - 1;
        for(int i = s.size() - 1 ; i >= 0 ; i--){
            if(s[i] > s[p_max]){
                p_max = i;
            }else if(s[i] < s[p_max]){
                p_change = i;
            }
            mxp[i] = p_max;
        }
        swap(s[p_change],s[mxp[p_change]]);
        istringstream(s) >> num;
        return num;
    }
};
int main(){
    return 0;
}