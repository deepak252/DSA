#include <bits/stdc++.h>

using namespace std;

class TreeNode{
public:
    int val;
    int height = 1;
    TreeNode* left = nullptr;
    TreeNode* right = nullptr;

    TreeNode(int val): val(val) {}
};

class AVLTree{
private:
    TreeNode* root;

    int getHeight(TreeNode* node){
        if(!node){
            return 0;
        }
        return node->height;
    }

    // left Subtree height - right subtree height
    int getBalanceFactor(TreeNode* node){
        if(!node){
            return 0;
        }
        return getHeight(node->left) - getHeight(node->right);
    }

    // Maximum value node in left subtree (rightmost node of left subtree)
    TreeNode* inorderPredecessor(TreeNode* node){
        node = node->left;
        while(node && node->right){
            node = node->right;
        }
        return node;
    }

    TreeNode* rightRotate(TreeNode* node){
        TreeNode* left = node->left;
        TreeNode* left_right = left->right;
        
        left->right = node;
        node->left = left_right;

        node->height = 1 + max(getHeight(node->left), getHeight(node->right));
        left->height = 1 + max(getHeight(left->left), getHeight(left->right));

        return left;
    }

    TreeNode* leftRotate(TreeNode* node){
        TreeNode* right = node->right;
        TreeNode* right_left = right->left;

        right->left = node;
        node->right = right_left;

        node->height = 1 + max(getHeight(node->left), getHeight(node->right));
        right->height = 1 + max(getHeight(right->left), getHeight(right->right));

        return right;
    }

    TreeNode* balanceNode(TreeNode* node){
        int factor = getBalanceFactor(node);
        if(factor > 1){
            // left >> right
            int factor_l = getBalanceFactor(node->left);
            if(factor_l < 0){
                // left-left < left-right
                node->left = leftRotate(node->left);
            }
            return rightRotate(node);
            
        }else if(factor < -1){
            // left << right
            int factor_r = getBalanceFactor(node->right);
            if(factor_r > 0){
                // right-left > right-right
                node->right = rightRotate(node->right);
            }
            return leftRotate(node);
        }
        return node;
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
        node->height = 1 + max(getHeight(node->left), getHeight(node->right));

        return balanceNode(node);
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
            if(!node->left){
                TreeNode* temp = node;
                node = node->right;
                delete temp;
            }else if(!node->right){
                TreeNode* temp = node;
                node = node->left;
                delete temp;
            }else{
                TreeNode* predecessor = inorderPredecessor(node);
                node->val = predecessor->val;
                node->left = remove(node->left, predecessor->val);
            }
        }
        if(!node){
            return nullptr;
        }
        node->height = 1 + max(getHeight(node->left), getHeight(node->right));
        return balanceNode(node);
    }

    void preorder(TreeNode* node){
        if(!node){
            return;
        }
        cout<<node->val<<" "<<node->height<<", ";
        preorder(node->left);
        preorder(node->right);
    }

    bool search(TreeNode* node, int key){
        if(!node){
            return false;
        }
        if(node->val == key){
            return true;
        }
        if(key < node->val){
            return search(node->left, key);
        }
        return search(node->right, key);
    }
public:
    AVLTree(): root(nullptr) {}

    int height(){
        return getHeight(root);
    }

    void insert(int val){
        root = insert(root, val);
    }

    void remove(int val){
        root = remove(root, val);
    }

    bool search(int key){
        return search(root, key);
    }

    void printPreorder(){
        if(!root){
            cout<<"empty"<<endl;
            return;
        }
        preorder(root);
        cout<<endl;
    }
};

void insert(AVLTree& tree, int from = 0, int to = 1000000, int del = 2){
    if(from < to){
        for(int i = from; i<=to; i+=del){
            tree.insert(i);
        }
    }else{
        for(int i = from; i>=to; i-=del){
            tree.insert(i);
        }
    }
}

void remove(AVLTree& tree, int from = 0, int to = 1000000, int del = 2){
    if(from < to){
        for(int i = from; i<=to; i+=del){
            tree.remove(i);
        }
    }else{
        for(int i = from; i>=to; i-=del){
            tree.remove(i);
        }
    }
}

void search(AVLTree& tree, int from = 0, int to = 1000000, int del = 2){
    if(from < to){
        for(int i = from; i<=to; i+=del){
            tree.remove(i);
        }
    }else{
        for(int i = from; i>=to; i-=del){
            tree.remove(i);
        }
    }
}

int main(){

    auto start = chrono::high_resolution_clock::now();

    

    AVLTree tree = AVLTree();

    // insert(tree); // 483.246 ms
    // remove(tree); // 829.587 ms
    // remove(tree, 1000000, 0, 2); // 805.648 ms
    // search(tree); // 831.129 ms

    insert(tree, 1000000, 0, 2); // 403.77 ms
    remove(tree); // 747.773 ms
    // remove(tree, 1000000, 0, 2); // 752.93 ms
    // search(tree); // 740.615 ms

    // for(int i=1; i<=100; i++){
    //     cout<<tree.search(i)<<endl;
    // }


    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> duration = end - start;
    cout << "Time taken: " << duration.count() << " ms\n";  // 415.592 ms

    return 0;

    // AVLTree tree = AVLTree();

    // for(int i = 1000000; i>0; i-=2){
    //     tree.insert(i);
    // }
    // cout<<tree.height()<<endl;

    // tree.remove(2);
    // tree.remove(4);
    // tree.remove(12);
    // tree.remove(100);

    // for(int i=1; i<=100; i++){
    //     cout<<tree.search(i)<<endl;
    // }
    // tree.printPreorder();

    return 0;   
}