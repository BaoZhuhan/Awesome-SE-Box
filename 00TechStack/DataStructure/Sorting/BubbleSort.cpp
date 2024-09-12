#include <bits/stdc++.h>
using namespace std ;

class BubbleSort{
private:

public:
    vector<int> bubblesort(vector<int> &a){
        for(int i = 0 ; i < a.size() - 1; i++ ){
            for(int j = 0 ; j < a.size() - i - 1; j++){
                if( a[j] > a[j+1] ) {
                    swap( a[j] , a[j+1]);
                }
            }
        }

        return a;
    }
    
};

int main(){
    return 0;
}