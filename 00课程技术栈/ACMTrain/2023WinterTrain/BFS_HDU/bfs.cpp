#include <bits/stdc++.h>
using namespace std;

/*算法思想：维护一个队列， 用于存放节点的信息。当访问到一个节点时侯，先访问该节点，然后将该节点的左右儿子分别入队列*/

void bfs(){
    queue<int> Q;
    int root ; 
    Q.push(root);
    while(!Q.empty()){
        int now = Q.front() ; 
        Q.pop();
        if(now + 1 == true) Q.push(now + 1) ; 
        if(now - 1 == true) Q.push(now - 1) ; 
    }
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    return 0;
}



