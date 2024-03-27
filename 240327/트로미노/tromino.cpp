#include <iostream>
#include <algorithm>
using namespace std;

int mask[6][3][3] = {
    {
        {1, 0, 0},
        {1, 1, 0},
        {0, 0, 0}
    },
    {
        {0, 1, 0},
        {1, 1, 0},
        {0, 0, 0}
    },
    {
        {1, 1, 0},
        {0, 1, 0},
        {0, 0, 0}
    },
    {
        {1, 1, 0},
        {1, 0, 0},
        {0, 0, 0}
    },
    {
        {1, 1, 1},
        {0, 0, 0},
        {0, 0, 0}
    },
    {
        {1, 0, 0},
        {1, 0, 0},
        {1, 0, 0}
    },
};

int arr[201][201];
int N, M;

int main() {
    cin >> N >> M;

    for (int y = 1; y <= N; y++) {
        for (int x = 1; x <= M; x++) {
            cin >> arr[y][x];
        }
    }
    int max_sum = -21e8;

    for (int y = 1; y <= N; y++) {
        for (int x = 1; x <= M; x++) {
            for (int i = 0; i < 6; i++) {
                int sum = 0;
                bool is_out = false;
                for (int r = 0; r < 3; r++) {
                    for (int c = 0; c < 3; c++) {
                        if (mask[i][r][c] == 0) continue;
                        int py = y + r;
                        int px = x + c;
                        if (py > N || px > M) is_out = true;
                        sum += arr[py][px];
                    }
                }
                if (is_out) continue;
                max_sum = max(max_sum, sum);
            }
        }
    }

    cout << max_sum << endl;

    return 0;
}