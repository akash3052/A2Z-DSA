class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = 0;
        for(auto element : nums){
            if(element != 0){
                nums[j++] = element;
            }
        }
        for(int i = j; i < nums.size(); i++){
            nums[i] = 0;
        }
    }
};

