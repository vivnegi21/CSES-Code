#include<bits/stdc++.h>
using namespace std;
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);
typedef long long ll;
typedef vector<int> vi;
int MOD = 1e9 + 7;

void solve() {
    int n; cin >> n;
    vector<int> coins(n);
    for (int &i : coins) cin >> i;

    int max_sum = n * 1000;
    vector<vector<bool>> dp(n + 1, vector<bool>(max_sum, false));
    dp[0][0] = true;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= max_sum; j++) {
            //if we can make j with (i-1)th idx we can make it with ith idx as well
            dp[i][j] = dp[i - 1][j];
            int left_sum_if_selected = j - coins[i - 1];
            if (left_sum_if_selected >= 0 && dp[i - 1][left_sum_if_selected]) dp[i][j] = true;
        }
    }

    vector<int> ans;
    for (int j = 1; j <= max_sum; j++) {
        if (dp[n][j]) ans.push_back(j);
    }
    cout << ans.size() << endl;
    for (int i : ans) {
        cout << i << endl;
    }
}
/****************************Functions here*******************************/
int main() {
    fast_io;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    //write code
    solve();
    return 0;
}
/***********************************Properties***************************************/
/*  Modulus Operator
(a+ b) mod m = (a mod m+ b mod m) mod m
(a? b) mod m = (a mod m? b mod m) mod m
(a· b) mod m = (a mod m· b mod m) mod m

*/
