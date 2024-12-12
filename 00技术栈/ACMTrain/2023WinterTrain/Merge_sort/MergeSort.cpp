#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int a[N];

void merge(int arr[], int tempArr[], int l, int mid, int r)
{
    int p_1 = l;
    int p_2 = mid + 1;
    int p_n = l;
    while (p_1 <= mid && p_2 <= r)
    {
        if (arr[p_1] >= arr[p_2])
            tempArr[p_n++] = arr[p_2++];
        else
            tempArr[p_n++] = arr[p_1++];
    }
    while (p_1 <= mid)
        tempArr[p_n++] = arr[p_1++];
    while (p_2 <= r)
        tempArr[p_n++] = arr[p_2++];

    for (int i = l; i <= r; ++i)
        arr[i] = tempArr[i];
}
void merge_sort(int arr[], int tempArr[], int l, int r)
{

    if (l < r)
    {
        int mid = (l + r) >> 1;
        merge_sort(arr, tempArr, l, mid);
        merge_sort(arr, tempArr, mid + 1, r);
        merge(arr, tempArr, l, mid, r);
    }
}

void solve(int arr[], int n)
{
    int tempArr[n];
    memset(tempArr, 0, sizeof(tempArr));
    merge_sort(arr, tempArr, 0, n - 1);
}

signed main(void)
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    solve(a, n);
    for (int i = 0; i < n; ++i)
        cout << a[i] << ' ';
    return 0;
}