#include<bits/stdc++.h>
using namespace std;

// TC: O(n*m)
// Aux space: O(n*m)
vector<vector<int>> memo;
int edit_distance_helper(string &A, string &B, int n, int m) {
    if (n == 0) { // Insert `m` number of characters in `A`.
        return m;
    }
    if (m == 0) { // Delete `n` number of characters from `A`.
        return n;
    }
    if (memo[n][m] != -1) {
        return memo[n][m];
    }

    int result = INT_MAX;
    if (A[n - 1] == B[m - 1]) {
        result = edit_distance_helper(A, B, n - 1, m - 1);
    }
    else {
        // Insert a character in A.
        result = min(result, 1 + edit_distance_helper(A, B, n, m - 1));

        // Delete a character from A.
        result = min(result, 1 + edit_distance_helper(A, B, n - 1, m));

        // Replace a character in A.
        result = min(result, 1 + edit_distance_helper(A, B, n - 1, m - 1));
    }

    memo[n][m] = result;
    return result;
}

int edit_distance(string A, string B) {

    int n = A.length();
    int m = B.length();

    memo = vector<vector<int>>(n + 1, vector<int> (m + 1, -1));

    return edit_distance_helper(A, B, n, m);
}

int main() {

    cout << edit_distance("abad", "abac") << endl;
    cout << edit_distance("anshuman", "antihuman") << endl;
    cout << edit_distance("hello", "yellow") << endl;
}
