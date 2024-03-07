#include <iostream>
#include <algorithm>
#include <climits>
#include <set>

#define MAX_N 100000

using namespace std;

int N, D;

struct Coord {
    int x;
    int y;

    bool operator<(const Coord& comp) const {
        return y < comp.y;
    }
} arr[MAX_N + 1];

struct Compare_x {
    bool operator()(const Coord& t, const Coord& v) const {
        if (t.x == v.x) return t.y < v.y;
        return t.x < v.x;
    }
};

set<Coord> range;

int get_min() {
    if (range.empty()) return 0;
    return range.begin()->y;
}

int get_max() {
    if (range.empty()) return 0;
    return range.rbegin()->y;
}

int main() {
    // freopen("input.txt", "r", stdin);

    cin >> N >> D;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i].x >> arr[i].y;
    }
    sort (arr + 1, arr + N + 1, Compare_x());

    int j = 0;
    int ans = INT_MAX;

    for (int i = 1; i < N; i++) {
        while (j < N  && get_max() - get_min() < D) {
            j++;
            range.insert(arr[j]);
        }
        if (get_max() - get_min() < D) break;
        ans = min(ans, arr[j].x - arr[i].x);
        range.erase(range.find(arr[i]));
    }

    if (ans == INT_MAX) cout << -1 << endl;
    else cout << ans << endl;

    return 0;
}

/*
2 4  6 12
4 10 3 15

10 7 3 5 13 17 3 6 9

*/