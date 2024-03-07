#include <iostream>

#define MAX_N 1000

using namespace std;

int n, k;
int arr[MAX_N + 1];
int prefix[MAX_N + 1];

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        prefix[i] = prefix[i - 1] + arr[i];
    }
    int cnt = 0;
    for (int i = 0; i <= n - 1; i++) {
        for (int j = 1; j <= n - i; j++) {
            int val_sum = prefix[j + i] - prefix[j - 1];
            if (val_sum == k) cnt++;
        }
    }
    
    cout << cnt << endl;

    return 0;
}