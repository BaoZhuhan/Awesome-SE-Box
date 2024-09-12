#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int alternatingSubarray(vector<int>& nums) {
        bool flag = false;
        int res = -1;
        int tmp = 0;
        for(int i = 1 ;i < nums.size() ; i++){
            if(flag == false and nums[i] == nums[i-1] + 1){
                flag = true;
                tmp = 2;
            }else if(flag == false){
                continue;
            }else if(flag == true and nums[i] == nums[i-2]){
                tmp++;
            }else if(flag == true){
                if(res < tmp){
                    res = tmp;
                }
                if(nums[i] == nums[i-1] + 1){
                    tmp = 2;
                }else{
                    flag = false;
                }
            }
        }
        if(tmp > res){
            res = tmp;
        }
        if(res == 0){
            res = -1;
        }
        return res;
    }
};


int main(){

    return 0;
}