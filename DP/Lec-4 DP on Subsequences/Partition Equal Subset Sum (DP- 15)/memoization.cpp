class Solution {
public:
    bool findSubsetSum(int index, int n, int target, vector<int> &input, vector<vector<int>> &dp){
        if(target == 0){
            return true;
        }
        if(index == n){
            return false;
        }
        if(dp[index][target] != -1){
            return dp[index][target];
        }
        bool exclude = findSubsetSum(index+1, n, target, input, dp);
        bool include = false;
        if(input[index] <= target){
            include = findSubsetSum(index+1, n, target-input[index], input, dp);
        }
        return dp[index][target] = exclude || include;
    }

    bool canPartition(vector<int>& nums) {
        int totalSum = 0, n = nums.size();
        for(auto num : nums){
            totalSum += num;
        }
        if(totalSum %2 != 0){
            return false;
        }else{
            vector<vector<int>> dp(n+1, vector<int>(totalSum/2 + 1, -1));
            return findSubsetSum(0, nums.size(), totalSum/2, nums, dp);
        }
    }
};


// TC = O(n*target)
// SC = O(n*target)

