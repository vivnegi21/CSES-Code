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
    int n; cin >> n;
    vector<vector<char>> grid(n, vector<char>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

    cout << solve(n - 1, n - 1, grid, n, dp);

    return 0;
}

/****************************Functions here*******************************/
int solve(int i, int j, vector<vector<char>> &grid, int n, vector<vector<int>> &dp) {
    //base condition: NOTE that '*' condition is placed first to satisty when n=1 ans '*' is the value it should give 0.
    if (grid[i][j] == '*') return 0;
    if (i == 0 && j == 0) return 1;

    if (dp[i][j] != -1) return dp[i][j];
    //left
    int ans = 0;
    //left
    if (isSafe(i, j - 1) && grid[i][j - 1] == '.') {
        ans += solve(i, j - 1, grid, n, dp);
        performMod(ans, MOD);
    }
    //up
    if (isSafe(i - 1, j) && grid[i - 1][j] == '.') {
        ans += solve(i - 1, j, grid, n, dp);
        performMod(ans, MOD);
    }
    return dp[i][j] = ans;
}

void performMod(int &num, int &m) {
    if (num >= m) num -= m;
}
bool isSafe(int i, int j) {
    if (i < 0 || j < 0) return false;
    return true;
}



/***********************************Properties***************************************/
/*  Modulus Operator
(a+ b) mod m = (a mod m+ b mod m) mod m
(a? b) mod m = (a mod m? b mod m) mod m
(a· b) mod m = (a mod m· b mod m) mod m

*/


