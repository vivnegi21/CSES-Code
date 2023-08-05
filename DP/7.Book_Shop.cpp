#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
int MOD = 1e9 + 7;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    //input
    int n, x;
    cin >> n >> x;
    vector<int> cost(n, 0), pages(n, 0);
    for (int &i : cost) cin >> i;
    for (int &i : pages) cin >> i;
    //tabulation approach: KnapSack Problem
    vector<vector<int>> dp(n + 1, vector<int>(x + 1, 0));
  
    //base condition
    //when idx=0
    for (int cst = 0; cst <= x; cst++) {
        if (cst >= cost[0]) dp[0][cst] = pages[0];
    }

    for (int i = 1; i < n; i++) {
        for (int cst = 0; cst <= x; cst++) {
            dp[i][cst] = dp[i - 1][cst];
            if (cst >= cost[i]) {
                dp[i][cst] = max(dp[i][cst], pages[i] + dp[i - 1][cst - cost[i]]);
            }
        }
    }
    cout << dp[n - 1][x] << endl;

    return 0;
}
/****************************Functions here*******************************/



/***********************************Properties***************************************/
/*  Modulus Operator
(a+ b) mod m = (a mod m+ b mod m) mod m
(a? b) mod m = (a mod m? b mod m) mod m
(a· b) mod m = (a mod m· b mod m) mod m

*/


