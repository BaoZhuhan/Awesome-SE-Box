#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct Student {
    string id;
    int score;
    int location_number;
    int local_rank;
    int final_rank;
};

bool cmp(const Student &a, const Student &b) {
    if (a.score != b.score)
        return a.score > b.score;
    else
        return a.id < b.id;
}

int main() {
    int N;
    cin >> N;
    vector<Student> total;
    for (int i = 1; i <= N; ++i) {
        int K;
        cin >> K;
        vector<Student> local;
        for (int j = 0; j < K; ++j) {
            Student stu;
            cin >> stu.id >> stu.score;
            stu.location_number = i;
            local.push_back(stu);
        }
        sort(local.begin(), local.end(), cmp);
        local[0].local_rank = 1;
        for (int j = 1; j < local.size(); ++j) {
            if (local[j].score == local[j - 1].score)
                local[j].local_rank = local[j - 1].local_rank;
            else
                local[j].local_rank = j + 1;
        }
        total.insert(total.end(), local.begin(), local.end());
    }
    sort(total.begin(), total.end(), cmp);
    total[0].final_rank = 1;
    for (int i = 1; i < total.size(); ++i) {
        if (total[i].score == total[i - 1].score)
            total[i].final_rank = total[i - 1].final_rank;
        else
            total[i].final_rank = i + 1;
    }
    cout << total.size() << endl;
    for (int i = 0; i < total.size(); ++i) {
        cout << total[i].id << " " << total[i].final_rank << " " << total[i].location_number << " "
             << total[i].local_rank << endl;
    }
    return 0;
}
