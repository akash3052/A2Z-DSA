class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> temp;
        int n = nums.size();
        k = k % n;
        // copying the first (n-k) elements into another vector
        for(int i = 0; i < (n-k); i++){
            temp.push_back(nums[i]);
        }
        // last k elements will be shifted to first k elements
        for(int i = (n-k); i < n; i++){
            nums[i-(n-k)] = nums[i];
        }
        // first (n-k) will be shifted to last (n-k)
        for(int i = k; i < n; i++){
            nums[i] = temp[i - k];
        }
    }
};


