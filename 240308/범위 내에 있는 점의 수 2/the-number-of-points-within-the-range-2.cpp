#include <iostream>
#include <set>

#define MAX_N 1000000

using namespace std;

int N, Q;
int arr[MAX_N + 1]; 
int prefix[MAX_N + 1];

int main() {
    cin >> N >> Q;
    while (N--) {
        int idx;
        cin >> idx;
        arr[idx] = 1;
    }
    for (int i = 0; i <= MAX_N; i++) {
        if (i == 0) prefix[i] = arr[i];
        else prefix[i] = prefix[i - 1] + arr[i];
    }
    while (Q--) {
        int l, r;
        cin >> l >> r;
        int ans = prefix[r] - prefix[l] + arr[l];
        cout << ans << endl;
    }

    return 0;
}

/*
0 1 2 3 4 5 6 7 8 9 10
0 0 1 1 0 1 0 1 0 0 0
0 0 1 2 2 3 3 4 4 4 4
2 3 - 2
2 4 - 2
*/