/*
 * Given the root of a binary tree, return the inorder traversal of its nodes' values.
 */

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<int> inorderTraversal(TreeNode* root) {
      vector<int> traverse;
      if (root == NULL) return traverse;
      if (root->left != NULL) traverse = inorderTraversal(root->left);
      traverse.push_back(root->val);
      if (root->right != NULL) {
          vector<int> right = inorderTraversal(root->right);
          traverse.insert(traverse.end(), right.begin(), right.end());
      }
      return traverse;
  }

