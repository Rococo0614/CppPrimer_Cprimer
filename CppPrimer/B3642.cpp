#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr){}
};

class BinearyTreeBuilder{
    public:
    TreeNode* buildtree(){
        int n;
        cin >> n;

        if(n == 0) return nullptr;

        vector<TreeNode*> nodes(n+1);
        vector<bool> isChild(n+1,false);

        for(int i = 1; i <= n; i++){
            nodes[i] = new TreeNode(i);
        }

        for(int i = 1; i <= n; i++){
            int left,right;
            cin >> left >> right;

            if(left != 0){
                nodes[i] -> left = nodes[left];
                isChild[left] = true;
            }

            if(right != 0){
                nodes[i] -> right = nodes[right];
                isChild[right] = true;
            }
        }

        TreeNode* root = nullptr;
        for(int i = 1; i <= n; i++){
            if(!isChild[i]){
                root = nodes[i];
                break;
            }
        }

        return root;
    }

    void preOrder(TreeNode* root){
        if(!root) return;
        cout << root->val << " ";
        preOrder(root->left);
        preOrder(root->right);
    }

    void inOrder(TreeNode* root){
        if(!root) return;
        inOrder(root->left);
        cout << root-> val << " ";
        inOrder(root->right);
    }

    void postOrder(TreeNode* root){
        if(!root) return;
        postOrder(root->left);
        postOrder(root->right);
        cout << root->val << " ";
    }

    void levelOrder(TreeNode* root){
        if(!root) return;

        queue<TreeNode*> q;
        q.push(root);

        while(q.empty()){
            TreeNode* node = q.front();
            q.pop();
            cout << node->val << " ";


            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
    }
};

int main(){
    BinearyTreeBuilder builder;

    TreeNode* root = builder.buildtree();

    builder.preOrder(root);
    cout << endl;

    builder.inOrder(root);
    cout << endl;

    builder.postOrder(root);
    cout << endl;



}
