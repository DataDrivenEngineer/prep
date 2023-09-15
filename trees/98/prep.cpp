#include <stdio.h>
#include <limits>

using namespace std;

struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool dfs(TreeNode *root, int64_t l, int64_t r)
{
  if (!root) return true;
  if (!(root->val > l && root->val < r))
  {
    return false;
  }
  bool isValidLeft = dfs(root->left, l, root->val);
  bool isValidRight = dfs(root->right, root->val, r);
  return isValidLeft && isValidRight;
}

bool isValidBST(TreeNode* root)
{
  return dfs(root, numeric_limits<int64_t>::min(), numeric_limits<int64_t>::max());
}

int main(int argc, char **argv)
{
//  TreeNode *root = new TreeNode(2, new TreeNode(1), new TreeNode(3));
//  TreeNode *root = new TreeNode(5, new TreeNode(1), new TreeNode(4, new TreeNode(3), new TreeNode(6)));
//  TreeNode *root = new TreeNode(5, new TreeNode(4), new TreeNode(6, new TreeNode(3), new TreeNode(7)));
  TreeNode *root = new TreeNode(32, new TreeNode(26, new TreeNode(19), 0), new TreeNode(47, 0, new TreeNode(56, 0, new TreeNode(27))));
  bool res = isValidBST(root);
  printf("%d\n", res);
  return 0;
}
