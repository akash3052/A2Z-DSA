class Solution {
  public:
    void solve(int index, int &n, vector<int> &input, int target, int &count){
        if(index == n){
            if(target == 0){
                count++;
            }
            return;
        }
        if(input[index] <= target){
            solve(index+1, n, input, target - input[index], count);
        }
        solve(index+1, n, input, target, count);
    }
    
    int perfectSum(vector<int>& arr, int target) {
        // code here
        int n = arr.size();
        int count = 0, index = 0;
        solve(index, n, arr, target, count);
        return count;
    }
};


// **Time complexity**: \( O(2^n) \), **Space complexity**: \( O(n) \).

// this solution is giving TLE for few test cases
