#include <bits/stdc++.h>
using namespace std;
int k[100];
int moves[100][100];
void minMoves(int n) //求k 
{
        int min = -1;
        moves[0][0] = 0;
        k[0] = 0;
        for(int i = 1;i<= n;i++)
        {
                min = 1000000000;
                for(int j=1;j<=i;j++)
                {
                        moves[i][j] = 2*moves[i-j][k[i-j]] -1 + (2<<(j-1)) ;
                        if(moves[i][j] < min)
                        {
                                min = moves[i][j];
                                k[i] = j;
                        }
                }
        }
}
void move(int a,int b)
{
	printf("%d --> %d\n",a,b);
}

void hanoi(int x,int a,int b,int c)
{
	if(x == 1)
		move(a,b);
	else
	{
		hanoi(x-1,a,c,b);
		move(a,b);
		hanoi(x-1,c,b,a);
	}
}

void fourhanoi(int x,int a,int b,int c,int d)
{
	if(x == 1)
		move(a,b);
	else
	{
		int tk = k[x];
		fourhanoi(x-tk,a,d,b,c);
		hanoi(tk,a,b,c);
		fourhanoi(x-tk,d,b,a,c);
	}
}

int solve()
{
	minMoves(65);

	int n;
	
	cin >> n;

	fourhanoi(n,1,2,3,4);
	return 0;
}
int main(){
    int T;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}

