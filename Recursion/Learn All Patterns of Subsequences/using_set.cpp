class Solution {
  public:
    void solve(string input, string op, set<string> &res, int index, int n){
        if(index >= n){
            res.insert(op);
            return;
        }
        solve(input, op+input[index], res, index+1, n);
        solve(input, op, res, index+1, n);
    }
  
    string betterString(string str1, string str2) {
        set<string> res1, res2;
        solve(str1, "", res1, 0, str1.size());
        solve(str2, "", res2, 0, str2.size());
        
        return res1.size() >= res2.size() ? str1 : str2;
    }
};

// The overall time complexity of the betterString function is O(2^n) + O(2^m).

// For a string of length n:
// Each character has 2 choices: to be included or not included.
// This results in 2^n different subsets.
// Thus, the number of recursive calls made by the solve function is 2^n. 
// For each recursive call, a subset string is created and potentially inserted into the set res, 
// which takes O(log(number of subsets)). 

// However, in terms of time complexity, the insertion into the set is dominated by the number of subsets, which is 2^n.

// Test Cases Passed: 
// 1014 /1116
// Time Limit Exceeded






