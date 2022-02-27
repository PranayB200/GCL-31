#include<bits/stdc++.h>
using namespace std;


// TC: O(n * m)
// Aux Space: O(n * m)
vector<vector<int>> memo;
int count_paths_helper(vector<vector<int>> &arr, int i, int j) {
    if (i == arr.size() - 1 and j == arr[0].size() - 1) {
        return 1;
    }
    if (i >= arr.size() or j >= arr[0].size()) {
        return 0;
    }

    if (arr[i][j] == 1) {
        return 0;
    }
    if (memo[i][j] != -1) {
        return memo[i][j];
    }

    int result = 0;

    // Move right.
    result += count_paths_helper(arr, i, j + 1);

    // Move down.
    result += count_paths_helper(arr, i + 1, j);

    memo[i][j] = result;
    return result;
}

int count_paths(vector<vector<int>> arr) {

    int n = arr.size();
    int m = arr[0].size();

    memo = vector<vector<int>> (n, vector<int> (m, -1));
    if (arr[0][0] == 1 or arr[n - 1][m - 1] == 1) {
        return 0;
    }
    return count_paths_helper(arr, 0, 0);
}


// TC: O(n * m)
int count_paths_iterative(vector<vector<int>> arr) {

    int n = arr.size();
    int m = arr[0].size();

    if (arr[0][0] == 1 or arr[n - 1][m - 1] == 1) {
        return 0;
    }

    vector<vector<int>> path_counts(n, vector<int> (m, 0));
    path_counts[0][0] = 1;

    // Filling the first col:
    for (int i = 1; i < n; i++) {
        if (arr[i][0] == 1) break;
        path_counts[i][0] = 1;
    }

    // Filling the first row:
    for (int j = 1; j < m; j++) {
        if (arr[0][j] == 1) break;
        path_counts[0][j] = 1;
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (arr[i][j] == 1) {
                continue;
            }
            else {
                path_counts[i][j] = path_counts[i][j - 1] + path_counts[i - 1][j];
            }
        }
    }

    return path_counts[n - 1][m - 1];
}

int main() {

    cout << count_paths({{0, 0, 0},
                        {0, 1, 0},
                        {0, 0, 0}}) << endl;

    cout << count_paths({{0, 1, 0, 1},
                        {0, 0, 0, 0},
                        {0, 0, 0, 0},
                        {0, 1, 1, 0}}) << endl;

    cout << count_paths_iterative({{0, 0, 0},
                        {0, 1, 0},
                        {0, 0, 0}}) << endl;

    cout << count_paths_iterative({{0, 1, 0, 1},
                        {0, 0, 0, 0},
                        {0, 0, 0, 0},
                        {0, 1, 1, 0}}) << endl;
}