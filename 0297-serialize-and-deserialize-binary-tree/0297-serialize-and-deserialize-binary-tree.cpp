
class Codec {
public:
    void serial(TreeNode* node, string& str){
        if(node == nullptr){
            str += "null";
        }else{
            str += to_string(node->val) + ",";
            serial(node->left, str); str += ",";
            serial(node->right, str);
        }
    }
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string str = "";
        serial(root, str);
        // cout << "str: " << str << endl;
        return str;
    }

    std::vector<std::string> string_split(std::string str, std::string delimiter){
        size_t pos = 0;
        std::string token;
        std::vector<std::string> result;

        //Style 2, can deal with all tokens inside the while loop
        while(true){
            pos = str.find(delimiter);
            //works even if pos is string::npos
            token = str.substr(0, pos);
            result.push_back(token);
            if(pos == string::npos) break;
            //pos+1 equals to 0, so the line below can't handle this situation
            str.erase(0, pos+delimiter.length());
        }
        return result;
    }
    
    TreeNode* deserial(queue<string>& q){
        string token = q.front(); q.pop();
        if(token == "null") return nullptr;
        TreeNode* root = new TreeNode(stoi(token));
        root->left = deserial(q);
        root->right = deserial(q);
        return root;
    };
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> tokens = string_split(data, ",");
        queue<string, deque<string>> q(deque<string>(tokens.begin(), tokens.end()));
        return deserial(q);
    }
};