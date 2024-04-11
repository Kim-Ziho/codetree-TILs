#include <iostream>
#include <algorithm>
#include <string>
#define LEFT 0
#define RIGHT 1

using namespace std;

int n, m, q;
int arr[101][101];

bool can_spread(int row, int tar) {
    for (int i = 1; i <= m; i++) 
        if (arr[row][i] == arr[tar][i]) 
            return true;
    
    return false;
}

void shift(int row, int dir) {
    if (dir == LEFT) {
        int tmp = arr[row][m];

        for (int i = m; i > 1; i--) {
            arr[row][i] = arr[row][i - 1];
        }
        arr[row][1] = tmp;
    }
    else if (dir == RIGHT) {
        int tmp = arr[row][1];

        for (int i = 1; i < m; i++) {
            arr[row][i] = arr[row][i + 1];
        }
        arr[row][m] = tmp;
    }
}

void change_dir(int& dir) {
    dir = dir == RIGHT ? LEFT : RIGHT;
}

void print_arr() {
    for (int y = 1; y <= n; y++) {
        for (int x = 1; x <= m; x++) {
            cout << arr[y][x] << ' ';
        }
        cout << endl;
    }
}

void simulator(int row, int dir) {
    //STEP1 : 바람의 영향으로 이동
    shift(row, dir);
    change_dir(dir);

    //STEP2 : 위쪽으로 전파
    for (int y = row, d = dir; y >= 2; y--) {
        if (can_spread(y, y - 1)) {
            shift(y - 1, d);
            change_dir(d);
        }
        else break;
    }

    //STEP3 : 아래쪽으로 전파
    for (int y = row, d = dir; y < n; y++) {
        if (can_spread(y, y + 1)) {
            shift(y + 1, d);
            change_dir(d);
        }
        else break;
    }
}

int main() {
    cin >> n >> m >> q;
    for (int y = 1; y <= n; y++) 
        for (int x = 1; x <= m; x++) 
            cin >> arr[y][x];

    for (int i = 0; i < q; i++) {
        int row;
        int dir;
        string direct;
        cin >> row >> direct;

        if (direct == "L") dir = LEFT;
        else if (direct == "R") dir = RIGHT;

        simulator(row, dir);
    }
    print_arr();

    // 여기에 코드를 작성해주세요.
    return 0;
}