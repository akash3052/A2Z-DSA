class Solution {
public:
    // bool findSubsetSum(int index, int n, int target, vector<int> &input, vector<vector<int>> &dp){
    //     if(target == 0){
    //         return true;
    //     }
    //     if(index == n){
    //         return false;
    //     }
    //     if(dp[index][target] != -1){
    //         return dp[index][target];
    //     }
    //     bool exclude = findSubsetSum(index+1, n, target, input, dp);
    //     bool include = false;
    //     if(input[index] <= target){
    //         include = findSubsetSum(index+1, n, target-input[index], input, dp);
    //     }
    //     return dp[index][target] = exclude || include;
    // }

    bool canPartition(vector<int>& nums) {
        int totalSum = 0, n = nums.size();
        for(auto num : nums){
            totalSum += num;
        }
        if(totalSum %2 != 0){
            return false;
        }else{
            vector<vector<int>> dp(n+1, vector<int>(totalSum/2 + 1, false));
            for(int i = 0; i <= n; i++){
                dp[i][0] = true;
            }

          // since index is going from 0 to n-1 in recursion, we are doing opposite here(n-1 to 0)  
          for(int index = n-1; index >= 0; index--){
                // since target is going from target to 0 in recursion, we are doing opposite here in tabulation
                for(int target = 0; target <= totalSum/2; target++){
                    // copy and paste the entire recursive step and replace function call with dp[index][target]
                    bool exclude = dp[index+1][target];
                    bool include = false;
                    if(nums[index] <= target){
                        include = dp[index+1][target-nums[index]];
                    }
                    dp[index][target] = exclude || include;
                }
            }

            return dp[0][totalSum/2];
        }
    }
};

// TC = O(n*target)
// SC = O(n*target)

  
