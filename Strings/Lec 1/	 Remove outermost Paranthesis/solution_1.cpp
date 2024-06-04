class Solution {
public:
    string removeOuterParentheses(string s) {
        string currString = "", finalString = "";
        stack<char> stk;
        for(auto ch : s){
            currString += ch;
            if(ch == '('){
                stk.push(ch);
            }else{
                stk.pop();
            }
            // Note : checking every valid parenthesis and removing '(' and ')' from them and adding that string in finalString
            if(stk.empty()){
                currString = currString.substr(1, currString.size() - 2);
                finalString += currString;
                currString = "";
            }
        }
        return finalString;
    }
};
