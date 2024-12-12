#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> tasks(n);
    for (int i = 0; i < n; i++) {
        cin >> tasks[i];
    }
    sort(tasks.begin(), tasks.end());
    int ans = abs(x - y);
    for (int i = 0; i < n; i++) {
        ans = min(ans, max(abs(x - tasks[i]), abs(y - tasks[i])));
    }

    cout << ans << endl;
    return 0;
}
