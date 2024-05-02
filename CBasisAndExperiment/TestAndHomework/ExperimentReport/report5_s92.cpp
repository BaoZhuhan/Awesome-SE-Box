#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

struct node
{
    int index = 0;
    int score = 0;
    int goal = 0;
    int af_goal = 0;
};

vector<node> arr;

void input()
{
    int i, j, p, q;
    cin >> i >> j >> p >> q;
    
    if(p == q){
        arr[i-1].score += 1;
        arr[j-1].score += 1;
        // cout << "p==q" << arr[i].index << ' ' << arr[j].index << "-->" << arr[i].score << ' ' << arr[j].score << endl;
    }else if(p > q){
        arr[i-1].score += 3;
        // cout << "p>q" << arr[i].index << ' ' << arr[j].index << "-->" << arr[i].score << ' ' << arr[j].score << endl;
    }else{
        arr[j-1].score += 3;
        // cout << "p<q" << arr[i].index << ' ' << arr[j].index << "-->" << arr[i].score << ' ' << arr[j].score << endl;
    }
    arr[i-1].goal += p;
    arr[i-1].af_goal += (p - q);
    arr[j-1].goal += q;
    arr[j-1].af_goal += (q - p);
}

bool cmp(node x, node y){
    if(x.score > y.score){
        return true;
    }else if(x.score < y.score){
        return false;
    }else if(x.af_goal > y.af_goal){
        return true;
    }else if(x.af_goal < y.af_goal){
        return false;
    }else if(x.goal > y.goal){
        return true;
    }else if(x.goal < y.goal){
        return false;
    }else if(x.index < y.index){
        return true;
    }else{
        return false;
    }    
}
int main()
{
    int n;
    cin >> n;
    
    for (int i = 1; i <= n; i++)
    {
        node tmp;
        tmp.index = i;
        arr.push_back(tmp);
    }
    
    int t = (n * (n - 1)) / 2;
    
    for (int i = 0; i < t; i++)
    {
        input();
    }

    
    sort(arr.begin(),arr.end(),cmp);
    
    // for(auto i : arr){
    //     cout << i.index << ' ' << i.score << ' ' << i.goal << ' ' << i.af_goal << endl;
    // }
    for(auto i : arr){
        cout << i.index << ' ';
    }
    
    return 0;
}