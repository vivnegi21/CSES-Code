#include<bits/stdc++.h>
using namespace std;
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);
typedef long long ll;
typedef vector<int> vi;
int MOD = 1e9 + 7;

void solve() {
    string s1, s2;
    cin >> s1 >> s2;

    int n = s1.size(), m = s2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    //base contion
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        dp[i][0] = i;
    }
    for (int j = 1; j <= m; j++) {
        dp[0][j] = j;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[i - 1] == s2[j - 1]) dp[i][j] = dp[i - 1][j - 1];
            else {
                int opt1 = 1 + dp[i][j - 1];
                int opt2 = 1 + dp[i - 1][j];
                int opt3 = 1 + dp[i - 1][j - 1];
                dp[i][j] = min(opt1, min(opt3, opt2));
            }
        }
    }
    /*for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }*/
    cout << dp[n][m] << endl;
}

/****************************Main Functions here*******************************/
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


