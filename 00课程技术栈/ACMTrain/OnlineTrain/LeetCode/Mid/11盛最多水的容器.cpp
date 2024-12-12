#include <bits/stdc++.h>
using namespace std ;


class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0 ;
        int left = 0 , right = height.size() - 1;
        while(left != right) {
            int h = (height[right] > height[left] ? 0 : 1);
            int tmp = (right - left) * height[(h == 0 ? left : right)];
            ans = ans > tmp ? ans : tmp;
            if(h == 0) left += 1;
            else right -= 1;
        } 
        return ans ;
    }
};


int main(){
    Solution s;
    int n ; 
    cin >> n ;
    vector<int> height(n);
    for(int i = 0 ; i < n ; i ++) {
        cin >> height[i];
    }
    cout << s.maxArea(height);
}