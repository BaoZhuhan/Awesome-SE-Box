#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    bool validPartition(vector<int>& nums) {
        vector<bool> dp(nums.size()+1,false);
        // dp[0] = true;
        for(int i = 1 ; i < nums.size() ; i++){
            // cout << "循环到i->" << i <<endl; 
            if(i == 1) if(nums[0] == nums[1]) {dp[i] = true;}
            if(i == 2) {
                if(nums[1] == nums[0] and nums[1] == nums[2]) {dp[i] = true;}
                if(nums[2] - nums[1] == 1 and nums[1] - nums[0] == 1) {dp[i] = true;}
            }
            if(i > 2){
                if(dp[i-2] == true and nums[i-1] == nums[i]) {dp[i] = true;}
                if(dp[i-3] == true ){
                    if(nums[i-2] == nums[i-1] and nums[i-1] == nums[i]) {dp[i] = true;}
                    if(nums[i] - nums[i-1] == 1 and nums[i-1] - nums[i-2] == 1) {dp[i] = true;}
                }
            }
        }
        // for(auto x : dp) cout << x << ' ';
        // cout << endl ;
        return dp[nums.size() - 1];
    }
};

int main(){
    int T; scanf("%d",&T);
    while(T--){
        int n ;scanf("%d",&n);
        vector<int> nums(n);
        for(int i = 0 ; i < n ;i++){
            scanf("%d",&nums[i]);
        }
        Solution s;
        printf("%d\n",s.validPartition(nums));
    }

    return 0;
}