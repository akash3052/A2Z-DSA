class Solution {
public:
    string removeOuterParentheses(string s) {
        string currString = "", finalString = "";
        int opened = 0;
        for(auto ch : s){
            if(ch == '(' && opened++ > 0){
                finalString += ch;
            }
            if(ch == ')' && opened-- > 1){
                finalString += ch;
            }
        }
        return finalString;
    }
};


