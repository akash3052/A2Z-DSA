class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        if (n == 1){
            return strs[0];
        }

        int minSize = INT_MAX;
        // finding minm size among all the strings present in the vector
        for(int i = 0; i < n; i++){
            string currVal = strs[i];
            minSize = min(minSize, int(currVal.size()));
        }
        
        bool mismatched = false;
        int j;
        
        Here j should be constant and i should vary as we are checking the first char of each string, then second char and so on..
        That's why outer loop is j and inner loop is i.
        // str[0][0]
        // str[1][0]
        // str[2][0]
        for(j = 0; j < minSize;  j++){
            for(int i = 1; i < n; i++){
                if(strs[i][j] != strs[i-1][j]){
                    mismatched = true;
                    break;
                }
            }
            if(mismatched == true){
                break;
            }
        }
        return strs[0].substr(0, j);

    }
};


