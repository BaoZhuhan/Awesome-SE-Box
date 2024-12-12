#include <bits/stdc++.h>
using namespace std ;

class SelectSort{
public:
    vector<int> selectsort(vector<int> &a){
        for(int i = 0 ; i < a.size() ; i++){
            int index = i;
            for(int j = i + 1 ; j < a.size() ; j++){
                if( a[j] > a[index]){
                    index = j;
                }
            }
            swap( a[i] , a[index]);
        }

        return a;
    }
};

int main(){
    return 0;
}
