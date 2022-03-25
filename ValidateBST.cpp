/*
 * Given the root of a binary tree, determine if it is a valid binary search tree (BST).
 * A valid BST is defined as follows:
 *		The left subtree of a node contains only nodes with keys less than the node's key.
 *		The right subtree of a node contains only nodes with keys greater than the node's key.
 *		Both the left and right subtrees must also be binary search trees.
 */
#include <vector>
#include <algorithm>
using namespace std;

#define nullptr NULL

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<int> valid_helper(TreeNode *root) {
    vector<int> minmax;
    if (root->left) {
        vector<int> left = valid_helper(root->left);
        if (left.size() > 0) {
            if (left[1] >= root->val) return minmax;
            minmax = {left[0], root->val};
        } else return minmax;
    }
    if (root->right) {
        vector<int> right = valid_helper(root->right);
        if (right.size() > 0) {
            if (right[0] <= root->val) {
                vector<int> ret;
                return ret;
            }
            if (minmax.size() > 0) minmax[1] = right[1];
            else minmax = {root->val, right[1]};
        } else {
            vector<int> ret;
            return ret;
        }
    }
    if (minmax.size() == 0) minmax = {root->val, root->val};
    return minmax;
}

bool isValidBST(TreeNode* root) {
    if (valid_helper(root).size() > 0) return true;
    else return false;
}

