//
// Created by lei.ge on 6/19/2020.
// ref: http://zxi.mytechroad.com/blog/leetcode/leetcode-669-trim-a-binary-search-tree/
// Runtime: 24 ms, faster than 73.92% of C++ online submissions for Trim a Binary Search Tree.
// Memory Usage: 23.9 MB, less than 23.09% of C++ online submissions for Trim a Binary Search Tree.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        if (!root) return nullptr;
        // val not in range, return the left/right subtrees
        if (root->val < L) {
            root = trimBST(root->right, L, R);
        }
        else if (root->val > R) {
            root = trimBST(root->left, L, R);
        }
        else {
            // val in [L, R], recusively trim left/right subtrees
            root->left = trimBST(root->left, L, R);
            root->right = trimBST(root->right, L, R);
        }
        return root;
    }

};

// here is the full program to delete trimmed nodes.
#include <iostream>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};

class Solution1 {
public:
    // with cleanup -> no memory leak
    TreeNode*& trimBST(TreeNode*& root, int L, int R) {
        if(!root) return root;

        if (root->val < L) {
            auto& result = trimBST(root->right, L, R);
            deleteTree(root->left);
            delete root;
            root = nullptr;
            return result;
        } else if (root->val > R) {
            auto& result = trimBST(root->left, L, R);
            deleteTree(root->right);
            delete root;
            root = nullptr;
            return result;
        } else {
            // recusively trim left/right subtrees
            root->left = trimBST(root->left, L, R);
            root->right = trimBST(root->right, L, R);
            return root;
        }
    }

    void deleteTree(TreeNode* &root) {
        if(!root) return;
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
        root = nullptr;
    }
};
void PrintTree(TreeNode* root) {
    if(!root) {
        cout<<"null ";
        return;
    };
    if(!root->left && !root->right) {
        cout<<root->val<<" ";
    } else {
        cout<<root->val<<" ";
        PrintTree(root->left);
        PrintTree(root->right);
    }
}
void PrintTree(TreeNode* root) {
    if(!root) {
        cout<<"null ";
        return;
    };
    if(!root->left && !root->right) {
        cout<<root->val<<" ";
    } else {
        cout<<root->val<<" ";
        PrintTree(root->left);
        PrintTree(root->right);
    }
}