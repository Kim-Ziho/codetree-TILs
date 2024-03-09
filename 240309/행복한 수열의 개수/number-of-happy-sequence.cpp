#include <iostream>

#define MAX_N 100

using namespace std;

int n, m;
int arr[MAX_N + 1][MAX_N + 1];

int main() {
    cin >> n >> m;
    for (int y = 1; y <= n; y++) {
        for (int x = 1; x <= n; x++) {
            cin >> arr[y][x];
        }
    }
    int ans = 0;

    for (int y = 1; y <= n; y++) {
        int cnt = 0;
        for (int x = 1; x <= n; x++) {
            if (arr[y][x] == arr[y][x - 1]) cnt++;
            else cnt = 0;
            if (cnt >= m - 1) {
                ans++;
                break;
            }
        }
    }
    for (int x = 1; x <= n; x++) {
        int cnt = 0;
        for (int y = 1; y <= n; y++) {
            if (arr[y][x] == arr[y - 1][x]) cnt++;
            else cnt = 0;
            if (cnt >= m - 1) {
                ans++;
                break;
            }
        }
    }

    cout << ans << endl;

    return 0;
}