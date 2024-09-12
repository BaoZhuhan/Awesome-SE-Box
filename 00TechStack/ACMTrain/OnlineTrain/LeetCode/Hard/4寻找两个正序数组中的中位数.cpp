#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> a;
        for(int i = 0 ;i < nums1.size() ;i++){
            a.push_back(nums1[i]);
        }
        for(int j = 0 ;j < nums2.size() ; j++){
            a.push_back(nums2[j]);
        }

        sort(a.begin(),a.end());
        if((int)a.size() % 2 == 1) {return a[a.size()/2 + 1];}
        else {return (a[a.size()/2] + a[a.size()/2 + 1])/2 ;}
    }
};

int main(){
    Solution s;
    return 0;

}