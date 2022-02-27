#include<bits/stdc++.h>
using namespace std;

// TC: O(n*n)
// Aux Space: O(n*n)

vector<vector<int>> memo;
int max_score_helper(vector<int> &arr, int i, int j) {

    if (i > j) {
        return 0;
    }
    if (memo[i][j] != -1) {
        return memo[i][j];
    }

    // Let's pick arr[i].
    int x = arr[i] + min(max_score_helper(arr, i + 2, j), 
                         max_score_helper(arr, i + 1, j - 1));

    // Let's pick arr[j];
    int y = arr[j] + min(max_score_helper(arr, i + 1, j - 1),
                         max_score_helper(arr, i, j - 2));
    

    memo[i][j] = max(x, y);
    return max(x, y);
}

int max_score(vector<int> arr) {
    int n = arr.size();
    memo = vector<vector<int>> (n, vector<int> (n, -1));
    return max_score_helper(arr, 0, (int)arr.size() - 1);
}

int main() {

    cout << max_score({5, 3, 7, 10}) << endl;
    cout << max_score({8, 15, 3, 7}) << endl;
}
