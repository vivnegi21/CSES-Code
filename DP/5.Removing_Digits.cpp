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
    //write code
    int n;
    cin >> n;
    int ans = solve(n);
    cout << ans;

    return 0;
}
/****************************Functions here*******************************/
unordered_map<int, int> dp;
int solve(int n) {
    //base condition
    if (n < 10) return 1;
    if (n == 10) return 2;

    if (dp.find(n) != dp.end()) return dp[n];

    string num = to_string(n);
    int ans = INT_MAX;
    for (char ch : num) {
        int part = (int)(ch - '0');
        if (part != 0) ans = min(ans, solve(n - part) + 1);
    }

    return dp[n] = ans;
}
/***********************************Properties***************************************/
/*  Modulus Operator
(a+ b) mod m = (a mod m+ b mod m) mod m
(a? b) mod m = (a mod m? b mod m) mod m
(a· b) mod m = (a mod m· b mod m) mod m

*/
