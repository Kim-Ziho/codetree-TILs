#include <iostream>
#include <algorithm>
using namespace std;

int dy[4] = {-1, -1, 1, 1};
int dx[4] = {1, -1, -1, 1};
int arr[21][21];
int n;

bool in_range(int y, int x) {
    return y <= n && x <= n && y > 0 && x > 0;
}

int get_sum(int y, int x, int w, int l) {
    int step[4] = {w, l, w, l};    
    int sum = 0;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < step[i]; j++) {
            y += dy[i];
            x += dx[i];
            if (y > n || x > n || y < 1 || x < 1) return 0;
            sum += arr[y][x];
        }
    }
    return sum;
}

int main() {
    int ans = 0;
    cin >> n;
    for (int y = 1; y <= n; y++) {
        for (int x = 1; x <= n; x++) {
            cin >> arr[y][x];
        }
    }
    for (int y = 1; y <= n; y++) {
        for (int x = 1; x <= n; x++) {
            for (int w = 1; w <= n; w++) {
                for (int l = 1; l <= n; l++) {
                    ans = max(ans, get_sum(y, x, w, l));
                }
            }
        }
    }
    cout << ans << endl;

    // 여기에 코드를 작성해주세요.
    return 0;
}