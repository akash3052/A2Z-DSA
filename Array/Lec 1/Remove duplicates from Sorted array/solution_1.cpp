class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0, k = 0, n = nums.size();
        while(i < n){
            int j = i+1;
            while(j < n && nums[i] == nums[j]){
                j++;
            }
            nums[k++] = nums[i];
            i = j;
        }
        return k;
    }
};

