#include <stdio.h>
#include <cmath>

using namespace std;

struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int val): val(val), left(0), right(0) {}
  TreeNode(int val, TreeNode *l, TreeNode *r): val(val), left(l), right(r) {}
};

static bool res = true;

int dfs(TreeNode *root, bool isLeft)
{
  if (!root) return -1;
  int lh = 1 + dfs(root->left, true);
  int rh = 1 + dfs(root->right, false);
  if (abs(lh - rh) > 1)
  {
    res = false;
  }
  return isLeft ? lh : rh;
}

bool isBalanced(TreeNode *root)
{
  dfs(root, false);
  return res;
}

int main(int argc, char **argv)
{
//  TreeNode *root = new TreeNode(3, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7)));
  TreeNode *root = new TreeNode(1, new TreeNode(2, new TreeNode(3, new TreeNode(4), new TreeNode(4)), new TreeNode(3)), new TreeNode(2));
  bool res = isBalanced(root);
  printf("%d\n", res);
  return 0;
}
