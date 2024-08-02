class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> charMap;
        unordered_map<char,char> reverseMap;
        for(int i = 0; i < s.size(); i++){
            if(charMap.find(s[i]) != charMap.end()){
                if(charMap[s[i]] != t[i]){
                    return false;
                }
            }else{
                // using reveseMap because if a character is mapped to some character, then we can't    map them to other character.   
                if(reverseMap.find(t[i]) != reverseMap.end()){
                    return false;
                }
                charMap[s[i]] = t[i];
                reverseMap[t[i]] = s[i];
            }
        }
        return true;
    }
};


