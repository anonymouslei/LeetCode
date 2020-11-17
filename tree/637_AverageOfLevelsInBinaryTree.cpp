//
// Created by leige on 7/23/2020.
//
// ref: http://zxi.mytechroad.com/blog/tree/leetcode-637-average-of-levels-in-binary-tree/

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
    // BFS
    // Runtime: 20 ms, faster than 91.22% of C++ online submissions for Average of Levels in Binary Tree.
    //Memory Usage: 22.2 MB, less than 100.00% of C++ online submissions for Average of Levels in Binary Tree.
public:
    vector<double> averageOfLevels(TreeNode* root) {
        if (root == nullptr) return {};
        vector<TreeNode*> curr;
        vector<TreeNode*> next;

        vector<double> ans;
        curr.push_back(root);
        while(!curr.empty())
        {
            long long sum = 0;
            for(const auto& item : curr)
            {
                sum += item->val;
                if(item->right) next.push_back(item->right);
                if(item->left) next.push_back(item->left);
            }
            ans.push_back(static_cast<double>(sum) / curr.size());

            curr.swap(next);
            next.clear();
        }
        return ans;
    }
};

class Solution {
    // DFS
    // Runtime: 32 ms, faster than 33.42% of C++ online submissions for Average of Levels in Binary Tree.
    //Memory Usage: 22.8 MB, less than 30.46% of C++ online submissions for Average of Levels in Binary Tree.
public:
    vector<double> averageOfLevels(TreeNode* root) {
        if (root==nullptr) return {};
        vector<pair<long long, int>> sum_count;

        preorder(root, sum_count, 0);
        vector<double> ans;
        for (const auto& item : sum_count)
        {
            ans.push_back(static_cast<double>(item.first) / item.second);
        }
        return ans;
    }
private:
    void preorder(TreeNode* root, vector<pair<long long, int>>& sum_count, int depth)
    {
        if (root==nullptr) return;
        if (depth >= sum_count.size())
            sum_count.push_back({0, 0});
        sum_count[depth].first += root->val;
        sum_count[depth].second ++;

        preorder(root->left, sum_count, depth + 1);
        preorder(root->right, sum_count, depth + 1);
    }
};
