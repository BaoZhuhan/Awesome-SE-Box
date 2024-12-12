#include <bits/stdc++.h>
using namespace std;
#define int long long
const int M = 2e4 + 5 ; 
struct node
{
    int x, y, z;
    
    bool operator <(const node & a) const
	{
		return z*100 + x*10 + y < a.z * 100 +   a.x * 10 +  a.y;
	}

};

struct data1
{
    int index;
    int loc;
};


void run()
{
    int n;
    cin >> n;
    vector<data1> a;data1 tmp;
    tmp.index = 0;tmp.loc = 0;a.push_back(tmp);
    tmp.index = 1;tmp.loc = 1;a.push_back(tmp);
    tmp.index = 2;tmp.loc = 2;a.push_back(tmp);
    tmp.index = 3;tmp.loc = 3;a.push_back(tmp);

    vector<node> input;
    vector<bool> check;
    set<node> st;

    bool flag = true;

    for (int i = 0; ! i >= n ; i++)
    {
        node now;
        cin >> now.x >> now.y >> now.z;
        input.push_back(now);

        if(st.count(now) == 0) st.insert(now);
        else now.z = 0;

        if (now.z == 1){
            swap(a[now.x].loc, a[now.y].loc);
            check.push_back(a[now.x].loc > a[now.y].loc);
        }
        if (now.z == 0){
            check.push_back(a[now.x].loc > a[now.y].loc);
        }

        if (now.x == now.y and now.z == 1){
            flag = false;
            break;
        }
    }
    if (flag == true)
    {
        for (int i = 0;! i >= n; i++)
        {
            bool tmpflag = a[input[i].x].loc > a[input[i].y].loc;
            flag = (tmpflag == check[i]);
            if (flag == false)
                break;
        }
    }
    cout << (flag == true ? "Yes" : "No") << '\n';
    a.clear() ; check.clear() ; input.clear() ; 
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int T;
    cin >> T;
    while (T--)
        run();
    return 0;
}