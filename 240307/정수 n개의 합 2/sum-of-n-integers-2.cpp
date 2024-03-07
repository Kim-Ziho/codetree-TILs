#include <iostream>
#include <algorithm>

#define MAX_N 100000

using namespace std;

int n, k;
int prefix_sum[MAX_N + 1];
int arr[MAX_N + 1];

int main() {
    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        prefix_sum[i] = prefix_sum[i - 1] + arr[i];
    }

    int max_sum = -21e8;
    int val_sum = 0;

    for (int i = k; i <= n; i++) {
        val_sum = prefix_sum[i] - prefix_sum[i - k];
        max_sum = max(max_sum, val_sum);
    }

    cout << max_sum << endl;


    return 0;
}