#include <iostream>
#include <algorithm>

#define MAX_N 100000

using namespace std;

int N, K, B;
int arr[MAX_N + 1];
int prefix[MAX_N + 1];

int main() {
    cin >> N >> K >> B;
    while (B--) {
        int idx;
        cin >> idx;
        arr[idx] = 1;
    }
    for (int i = 1; i <= N; i++) {
        prefix[i] = prefix[i - 1] + arr[i];
    }
    int min_cnt = 21e8;
    int cnt = 0;
    for (int i = K; i <= N; i++) {
        cnt = prefix[i] - prefix[i - K];
        min_cnt = min(min_cnt, cnt);
    }
    cout << min_cnt << endl;

    return 0;
}

/*
1 2 3 4 5 6 7 8 9 10
1 1 0 0 1 0 0 0 1 1

*/