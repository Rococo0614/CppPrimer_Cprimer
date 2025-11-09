#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct StudentValue {
    long long value;
    int id;

    bool operator<(const StudentValue& other) const {
        return value < other.value;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, p, s;
    cin >> n >> p >> s;

    vector<pair<long long, int>> a_sorted(n);
    vector<long long> a_val(n + 1), b_val(n + 1);
    for (int i = 0; i < n; ++i) {
        a_sorted[i].second = i + 1;
        cin >> a_sorted[i].first;
        a_val[i + 1] = a_sorted[i].first;
    }
    for (int i = 0; i < n; ++i) {
        cin >> b_val[i + 1];
    }

    sort(a_sorted.begin(), a_sorted.end(), greater<pair<long long, int>>());

    vector<int> op(n + 1, 0); // 0: unchosen, 1: programming, 2: sports
    long long total_score = 0;
    
    priority_queue<StudentValue> pq_a_unselected, pq_b_unselected, pq_b_minus_a_selected;

    for (int i = 0; i < p; ++i) {
        int stud_id = a_sorted[i].second;
        op[stud_id] = 1;
        total_score += a_sorted[i].first;
    }

    for (int i = 1; i <= n; ++i) {
        if (op[i] == 1) {
            pq_b_minus_a_selected.push({b_val[i] - a_val[i], i});
        } else {
            pq_a_unselected.push({a_val[i], i});
            pq_b_unselected.push({b_val[i], i});
        }
    }

    for (int i = 0; i < s; ++i) {
        long long gain1 = -2e18; // Recruit
        long long gain2 = -2e18; // Swap

        while (!pq_b_unselected.empty() && op[pq_b_unselected.top().id] != 0) {
            pq_b_unselected.pop();
        }
        if (!pq_b_unselected.empty()) {
            gain1 = pq_b_unselected.top().value;
        }

        while (!pq_b_minus_a_selected.empty() && op[pq_b_minus_a_selected.top().id] != 1) {
            pq_b_minus_a_selected.pop();
        }
        while (!pq_a_unselected.empty() && op[pq_a_unselected.top().id] != 0) {
            pq_a_unselected.pop();
        }

        if (!pq_b_minus_a_selected.empty() && !pq_a_unselected.empty()) {
            gain2 = pq_b_minus_a_selected.top().value + pq_a_unselected.top().value;
        }

        if (gain1 > gain2) {
            total_score += gain1;
            int stud_id = pq_b_unselected.top().id;
            op[stud_id] = 2;
            pq_b_unselected.pop();
        } else {
            total_score += gain2;
            int p_stud_id = pq_b_minus_a_selected.top().id;
            int u_stud_id = pq_a_unselected.top().id;
            pq_b_minus_a_selected.pop();
            pq_a_unselected.pop();
            
            op[p_stud_id] = 2;
            op[u_stud_id] = 1;
            
            pq_b_minus_a_selected.push({b_val[u_stud_id] - a_val[u_stud_id], u_stud_id});
        }
    }

    cout << total_score << endl;
    bool first = true;
    vector<int> p_team_final, s_team_final;
    for (int i = 1; i <= n; ++i) {
        if (op[i] == 1) p_team_final.push_back(i);
        if (op[i] == 2) s_team_final.push_back(i);
    }
    
    for (int i = 0; i < p_team_final.size(); ++i) {
        cout << p_team_final[i] << (i == p_team_final.size() - 1 ? "" : " ");
    }
    cout << endl;

    for (int i = 0; i < s_team_final.size(); ++i) {
        cout << s_team_final[i] << (i == s_team_final.size() - 1 ? "" : " ");
    }
    cout << endl;

    return 0;
}




