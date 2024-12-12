#include <bits/stdc++.h>
using namespace std;

/*
TODO:why can't "vector<int*> arr" work , and how to use pointer -> vector .
FIXME:make sure data can be transfrom from "vector<int> a" to "vector<int> arr" 
*/
const int N = 1e5 + 5 ; 
vector<int*> a(N , 0);

void merge(vector<int*> &arr , vector<int*> &tempArr , int l , int mid , int r){
    int p_1 = l ; 
    int p_2 = mid + 1;
    int p_n = r ; 
    while(p_1 <= mid && p_2 <= r){
        if(arr[p_1] >= arr[p_2]) tempArr[p_n++] = arr[p_2++];
        else tempArr[p_n++] = arr[p_1]++;
    }
    while(p_1 <= mid) tempArr[p_n++] = arr[p_1++] ;
    while(p_2 <= r) tempArr[p_n++] = arr[p_2++] ;
    for(int i = l ; i <= r ; ++i ) arr[i] = tempArr[i];
}

void merge_sort(vector<int*> &arr , vector<int*> &tempArr , int l , int r){
    if(l < r){
        int mid = (l + r) >> 1;
        merge_sort(arr, tempArr , l , mid);
        merge_sort(arr,tempArr , mid+1 , r);
        merge(arr , tempArr , l , mid , r);
    }
}

void run(vector<int*> &arr , int n){
    vector<int*> tempArr(n , 0);
    merge_sort(arr , tempArr , 0 , n - 1);
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    
    int n ; cin >> n ; 
    for (int i = 0 ; i < n ; ++i ) {
        cin >> *(a[i]);
    }
    run(a, n);
    for (int i = 0 ; i < n ; ++i ) {
        cout << *(a[i]) << ' ' ;
    }
    return 0;
}