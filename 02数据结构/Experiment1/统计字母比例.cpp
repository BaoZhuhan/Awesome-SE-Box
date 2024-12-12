#include <bits/stdc++.h>
using namespace std;

struct node {
    string loc;
    char wrd;
    string nxt;    
};

vector<node> a;
vector<int> ans(26,0);
int sum;

void run(){
    string head;
    int n;
    cin >> head >> n ;

    for(int i = 0 ; i < n ; i++) {
        node now;
        cin >> now.loc >> now.wrd >> now.nxt;
        a.push_back(now);
    } 

    bool flag = true ;
    string p = head ;

    while(flag == true){
        for(int i = 0 ; i < n ; i++) {
            if(a[i].loc == p){
                ans[(a[i].wrd - 'A')]++;
                sum++;
                p = a[i].nxt;
                break;
            }
        }
        if(p == "-1") flag = false;
    } 

    for(int i = 0 ; i < 26 ; i++){
        if(ans[i] != 0 ) printf("%c %.2f\%\n",'A'+i , ((float)ans[i]/(float)sum)*100  );
    }
}
int main(){
    run();
    return 0;
}