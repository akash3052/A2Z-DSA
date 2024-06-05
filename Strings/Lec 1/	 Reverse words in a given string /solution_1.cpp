class Solution {
public:
    string reverseWords(string s) {
        string temp , res = "";
        vector<string> v;
        int n = s.length();
        for(int i = 0; i < n; i++){
            temp = "";
            while(s[i] == ' ' && i < n){
                i++;
            }
            while(s[i] != ' ' && i < n){
                temp += s[i];
                i++;
            }
            if(!temp.empty()){
                v.push_back(temp);
            }
        }
        reverse(v.begin(), v.end());
        for(int i = 0; i < v.size(); i++){
            res += v[i];
            if(i != v.size() - 1){
                res += " ";
            }
        }
        return res;
    }
};

