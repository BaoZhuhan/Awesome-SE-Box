#include <bits/stdc++.h>
using namespace std;


const int N = 1e5 + 5;
 
struct node{
    int next[30];
    int cnt ;

}tree[N];

struct dirtree:vector<node>{
    int total = 1;// how much size vector used
    dirtree(){
        resize(N);
    }
    void insert(string s){
        int cur = 0;
        for(int i = 0 ; i < s.size() ; i++){
            int to = s[i] - 'a';
            if(at(cur).next[to] != 0){
                cur = at(cur).next[to];
            }else{
                at(cur).next[to] = total++;
                cur = total -1;
            }
            at(cur).cnt++ ;
        }

    }
    int query(string s){
        int cur = 0;
        for(int i = 0 ; i < s.size() ; i++){
            int to = s[i] - 'a';
            if(at(cur).next[to] != 0){
                cur = at(cur).next[to];
            }else{
                return 0;
            }
            
        }
        if(at(cur).cnt > 0) return 1;
    }

};
