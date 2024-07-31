#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pb push_back 

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> v;
        queue<TreeNode*> q;
        if(root == NULL) return v;
        q.push(root);
        while(!q.empty()) {
            int size = q.size();
            vector<int> temp;
            for(int i = 0; i < size; i++) {
                TreeNode* curr = q.front();
                q.pop();
                temp.push_back(curr->val);
                if(curr->left != NULL) q.push(curr->left);
                if(curr->right != NULL) q.push(curr->right);
            }
            v.push_back(temp);
        }
        return v;
    }


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);





    return 0;
}