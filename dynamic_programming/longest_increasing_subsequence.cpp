// Tutorial: https://www.geeksforgeeks.org/longest-increasing-subsequence-dp-3/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// longest increasing subsequence ending with index n
// dynamic programming solution
size_t longest_increasing_subsequence_dp(vector<int> &array){
    vector<size_t> dp(array.size(), 1);

    for(int i = 1;i < array.size();i++){
        for(int j = 0;j < i;j++){
            if(array[j] < array[i])
                dp[i] = max(dp[i], dp[j] + 1);
        }
    }

    return *max_element(dp.begin(), dp.end());
}

// longest increasing subsequence ending with index n
// recursive solution
size_t longest_increasing_subsequence(vector<int> &array, size_t n){
    if(n == 0)
        return 1;
    
    size_t lis = 1, res = 1;

    for(size_t i = 0;i <= n - 1;i++){
        res = longest_increasing_subsequence(array, i);

        if(array[i] <= array[n]){
            lis = max(lis, res + 1);
        }
    }

    return lis;
}

int main(int argc, char *argv[]){
    if(argc < 2){
        cerr << "USAGE: ./" << argv[0] << " [array]" << endl;
        return 1;
    }

    size_t n = argc - 1;
    vector<int> array(n);
    for(int i = 0;i < n;i++){
        array[i] = atoi(argv[i+1]);
    }

    cout << longest_increasing_subsequence_dp(array) << endl;

    return 0;
}