
struct Node{
    Node* links[26];
    bool flag;

    bool containsKey(char ch){
        return links[ch - 'a'] != NULL;
    }

    void put(char ch, Node* node){
        links[ch - 'a'] = node;
    }

    Node* get(char ch){
        return links[ch - 'a'];
    }

    void setEnd(){
        flag = true;
    }

    bool isEnd(){
        return flag;
    }
};

class Trie {
private:
    Node* root;
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* currNode = root;
        for(auto character : word){
            if(!currNode->containsKey(character)){
                currNode->put(character, new Node());
            }
            currNode = currNode->get(character);
        }
        currNode->setEnd();
    }
    
    bool search(string word) {
        Node* currNode = root;
        for(auto c : word){
            if(!currNode->containsKey(c)){
                return false;
            }
            currNode = currNode->get(c);
        }
        return currNode->isEnd();
    }
    
    bool startsWith(string prefix) {
        Node* currNode = root;
        for(auto c : prefix){
            if(!currNode->containsKey(c)){
                return false;
            }
            currNode = currNode->get(c);
        }
        return true;
    }
};



