#include <iostream>

using namespace std;

class TreeNode{
public:
    int val;
    TreeNode* left = nullptr;
    TreeNode* right = nullptr;

    TreeNode(int val){
        this->val = val;
    }
};

class BST {
private:
    TreeNode* root;

    void inorder(TreeNode* node){
        if(!node){
            return;
        }
        inorder(node->left);
        cout<<node->val<<" ";
        inorder(node->right);
    }

    TreeNode* insert(TreeNode* node, int val){
        if(!node){
            return new TreeNode(val);
        }
        if(val < node->val){
            node->left = insert(node->left, val);
        }else if(val > node->val){
            node->right = insert(node->right, val);
        }
        return node;
    }

    TreeNode* remove(TreeNode* node, int val){
        if(!node){
            return nullptr;
        }
        if(val < node->val){
            node->left = remove(node->left, val);
        }else if(val > node->val){
            node->right = remove(node->right, val);
        }else{
            // val = node->val
            if(!node->left){
                TreeNode* right = node->right;
                delete node;
                return right;
            }
            if(!node->right){
                TreeNode* left = node->left;
                delete node;
                return left;
            }
            TreeNode* predecessor = inorderPredecessor(node);
            node->val = predecessor->val;
            node->left = remove(node->left, predecessor->val);
        }
        return node;
    }

    // The predecessor of a node is the node that immediately precedes it in an inorder traversal.
    // It has the largest value less than the given node's value
    // Maximum value node in the left subtree
    TreeNode* inorderPredecessor(TreeNode* node){
        node = node->left;
        while(node && node->right){
            node = node->right;
        }
        return node;
    }

public:
    BST(): root(nullptr) {}

    void insert(int val){
        root = insert(root, val);
    }

    void remove(int val){
        root = remove(root, val);
    }

    void show(){
        if(!root){
            cout<<"empty"<<endl;
            return;
        }
        inorder(root);
        cout<<endl;
    }
};


int main(){
    BST bst = BST();
    bst.insert(5);
    bst.show();
    bst.insert(10);
    bst.show();
    bst.insert(1);
    bst.show();
    bst.insert(8);
    bst.show();

    bst.remove(5);
    bst.show();
    bst.remove(10);
    bst.show();
    bst.remove(1);
    bst.show();
    bst.remove(8);
    bst.show();

    return 0;


}
