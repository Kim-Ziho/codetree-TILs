#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n, m;
int arr[21][21];
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, 1, -1};

struct Node {
    int y;
    int x;
    int lev;
};

int get_cost(int k) {
    return k * k + (k + 1) * (k + 1);
}

int get_max_gold(int y, int x) {
    int ret = 0;
    queue<Node> q;
    int used[21][21] = {0};
    int gold = 0;
    
    q.push({y, x, 0});
    used[y][x] = 1;

    while (!q.empty()) {
        Node now = q.front();
        q.pop();
        
        if (arr[now.y][now.x]) gold++;
        if (gold * m >= get_cost(now.lev)) ret = gold;

        for (int i = 0; i < 4; i++) {
            int ny = now.y + dy[i];
            int nx = now.x + dx[i];
            if (ny < 1 || nx < 1 || ny > n || nx > n) continue;
            if (used[ny][nx]) continue;
            used[ny][nx] = 1;
            q.push({ny, nx, now.lev + 1});
        }
    }    

    return ret;
}

int main() {
    int ans = -1;
    cin >> n >> m;
    for (int y = 1; y <= n; y++) {
        for (int x = 1; x <= n; x++) {
            cin >> arr[y][x];
        }
    }
    for (int y = 1; y <= n; y++) {
        for (int x = 1; x <= n; x++) {
            ans = max(ans, get_max_gold(y, x));
        }
    }

    cout << ans << endl;
    // 여기에 코드를 작성해주세요.
    return 0;
}