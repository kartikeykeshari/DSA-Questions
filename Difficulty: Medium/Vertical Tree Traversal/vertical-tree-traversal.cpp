/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    vector<vector<int>> verticalOrder(Node *root) {
        if(root == NULL) return {};
        map<int, map<int, vector<int>>> mp;
        
        queue<pair<Node*, pair<int, int>>> q;
        q.push({root, {0,0}});
        
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            
            Node* node = p.first;
            int x = p.second.first;
            int y = p.second.second;
            
            mp[x][y].push_back(node->data);
            if(node->left) q.push({node->left, {x-1, y+1}});
            if(node->right) q.push({node->right, {x+1, y+1}});
        }
        
        vector<vector<int>> ans;
        
        for(auto p : mp){
            vector<int> col;
            for(auto q : p.second){
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};