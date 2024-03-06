#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <climits>

#define MAX_N 100000

using namespace std;

int N, D;

struct Coord {
    int x;
    int y;

    bool operator<(const Coord& comp) const {
        return x < comp.x;
    }
} arr[MAX_N];

int main() {
    cin >> N >> D;
    for (int i = 0; i < N; i++) {
        cin >> arr[i].x >> arr[i].y;
    }
    sort (arr, arr + N);

    int j = 0;
    int ans = INT_MAX;
    int mini = arr[0].y;
    int maxi = arr[0].y;

    for (int i = 0; i < N - 1; i++) {
        if (i == j) {
            mini = arr[i].y;
            maxi = arr[i].y;
        }
        while (j < N && abs(maxi - mini) < D) {
            j++;
            mini = min(mini, arr[j].y);
            maxi = max(maxi, arr[j].y);
        }
        if (j == N) break;
        ans = min(ans, arr[j].x - arr[i].x);
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