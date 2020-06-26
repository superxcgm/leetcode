//
// Created by Yujia Li  on 2020/6/3.
//

#include <iostream>
#include <algorithm>
#include <memory.h>

using namespace std;

const int len = 1002;

int value[len];
int cost[len];

int dp[len];

int main() {
    int T;

    cin >> T;

    while (T--) {
        int N, V;
        cin >> N >> V;
        for (int i = 0; i < N; i++) {
            cin >> value[i + 1];
        }
        for (int i = 0; i < N; i++) {
            cin >> cost[i + 1];
        }

        memset(dp, 0, sizeof(int) * len);

        for (int i = 1; i <= N; i++) {
            for (int j = V; j >= cost[i]; j--) {
//                if (cost[i] > j) {
//                    dp[i][j] = dp[i - 1][j];
//                } else {
                    dp[j] = max(dp[j], dp[j - cost[i]] + value[i]);
//                }
//                cout << dp[i][j] << " ";
            }
//            cout << endl;
        }
        cout << dp[V] << endl;
    }

    return 0;
}