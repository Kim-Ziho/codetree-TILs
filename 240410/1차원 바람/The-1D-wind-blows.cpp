#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

void left_wind(int);
void right_wind(int);
bool can_spread(int, int);

int N, M, Q;
int arr[101][101];
bool is_moved[101];

bool can_spread(int row, int tar) {
    for (int i = 1; i <= M; i++) {
        if (arr[row][i] == arr[tar][i]) return true;
    } 
    return false;
}

void left_wind(int row) {
    is_moved[row] = true;
    int tmp = arr[row][M];

    for (int i = M; i > 1; i--) {
        arr[row][i] = arr[row][i - 1];
    }
    arr[row][1] = tmp;
    
    if (row + 1 <= N && 
        !is_moved[row + 1] && 
        can_spread(row, row + 1)) right_wind(row + 1);
    if (row - 1 > 0 && 
        !is_moved[row - 1] && 
        can_spread(row, row - 1)) right_wind(row - 1);
}

void right_wind(int row) {
    is_moved[row] = true;
    int tmp = arr[row][1];

    for (int i = 1; i < M; i++) {
        arr[row][i] = arr[row][i + 1];
    }
    arr[row][M] = tmp;

    if (row + 1 <= N && 
        !is_moved[row + 1] && 
        can_spread(row, row + 1)) left_wind(row + 1);
    if (row - 1 > 0 && 
        !is_moved[row - 1] && 
        can_spread(row, row - 1)) left_wind(row - 1);
}

int main() {
    cin >> N >> M >> Q;
    for (int y = 1; y <= N; y++) {
        for (int x = 1; x <= M; x++) {
            cin >> arr[y][x];
        }
    }
    for (int i = 0; i < Q; i++) {
        int row;
        string direct;
        cin >> row >> direct;
        
        for (int i = 1; i <= M; i++)
            is_moved[i] = false;

        if (direct == "L") left_wind(row);
        else if (direct == "R") right_wind(row);
    }
    for (int y = 1; y <= N; y++) {
        for (int x = 1; x <= M; x++) {
            cout << arr[y][x] << ' ';
        }
        cout << endl;
    }

    // 여기에 코드를 작성해주세요.
    return 0;
}