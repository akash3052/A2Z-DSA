class Solution {
public:
    void solve(int open, int close, string op, vector<string> &res){
        if(open == 0 && close == 0){
            res.push_back(op);
            return;
        }
        if(open != 0){
            op.push_back('(');
            solve(open-1, close, op, res);
            op.pop_back();
        }

        if(close > open){
            op.push_back(')');
            solve(open, close-1, op, res);
            op.pop_back();
        }
        return;
    }

    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string op = "";
        // note we are assigning open = n and close = n
        solve(n, n, op, res);
        return res;
    }
};
