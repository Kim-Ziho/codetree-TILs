#include <iostream>
#include <algorithm>
#include <set>
#include <climits>

#define MAX_N 100000

using namespace std;

// 변수 선언
int n, d;
pair<int, int> point[MAX_N + 1];
set<pair<int, int> > point_count;

int get_min() {
    if(point_count.empty()) return 0;
    return point_count.begin()->first; 
}

int get_max() {
    if(point_count.empty()) return 0;
    return point_count.rbegin()->first;
}

int main() {
    // 입력:
    cin >> n >> d;
    for(int i = 1; i <= n; i++) {
        cin >> point[i].first >> point[i].second;
    }

    sort(point + 1, point + n + 1);

    // 가능한 구간 중 최소 크기를 구합니다.
    int ans = INT_MAX;

    // 구간을 잡아봅니다.
    int j = 0;
    for(int i = 1; i <= n; i++) {
        // y좌표 차가 d가 되기 전까지 계속 진행합니다.
        while(j + 1 <= n && get_max() - get_min() < d) {
            point_count.insert({point[j + 1].second, point[j + 1].first});
            j++;
        }

        // 만약 최대한 이동했는데도
        // y좌표 차가 d가 되지 못했다면
        // 탐색을 종료합니다.
        if(get_max() - get_min() < d)
            break;

        // 현재 구간 [i, j]는 
        // point[i]를 시작점으로 하는
        // 가장 짧은 구간이므로
        // 구간 크기 중 최솟값을 갱신합니다.
        ans = min(ans, point[j].first-point[i].first);
        
        // 다음 구간으로 넘어가기 전에
        // point[i]에 해당하는 값은 point_count에서 지워줍니다.
        point_count.erase(point_count.find({point[i].second, point[i].first}));
    }

    // 만약 불가능하다면
    // -1을 답으로 합니다.
    if(ans == INT_MAX) cout << -1;
    else cout << ans;
    return 0;
}