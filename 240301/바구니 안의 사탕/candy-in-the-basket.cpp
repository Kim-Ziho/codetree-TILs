#include <iostream>
#include <algorithm>

#define MAX_N 100000

using namespace std;

struct Candy {
    int x;
    int cnt;

    bool operator<(const Candy& comp) const {
        return x < comp.x;
    }
} candies[MAX_N];

int n, k;

int main() {
    // freopen("input.txt", "r", stdin);

    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> candies[i].cnt >> candies[i].x;
    }

    sort(candies, candies + n);
    
    int ans = 0;
    int j = 0;
    int sum = 0;
    
    for (int i = 0; i < n; i++) {
        while (j < n && candies[j].x - candies[i].x <= 2 * k) {
            sum += candies[j].cnt;
            j++;
        }
        ans = max(ans, sum);
        sum -= candies[i].cnt;
    }

    cout << ans << endl;
}

// 1 5
// 2 2
// 7 4
// 15 10
// 22 12