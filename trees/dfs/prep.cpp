#include <stdio.h>

using namespace std;

struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int val): val(val), left(0), right(0) {}
  TreeNode(int val, TreeNode *l, TreeNode *r): val(val), left(l), right(r) {}
};

void dfs(TreeNode *root)
{
  if (root)
  {
    printf("%d ", root->val);
    dfs(root->left);
    dfs(root->right);
  }
}

int main(int argc, char **argv)
{
  TreeNode *root = new TreeNode(1, new TreeNode(4, 0, new TreeNode(3, new TreeNode(7), new TreeNode(2))), new TreeNode(5, 0, new TreeNode(9)));
  dfs(root);
  // expected printout: 1 4 3 7 2 5 9
  return 0;
}
