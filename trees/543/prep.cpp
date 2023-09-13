#include <stdio.h>
#include <algorithm>

using namespace std;

struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int val): val(), left(0), right(0) {}
  TreeNode(int val, TreeNode *l, TreeNode *r): val(), left(l), right(r) {}
};

static int res = 0;

int getHeight(TreeNode *root)
{
  if (!root) return -1;
  int lh = getHeight(root->left);
  int rh = getHeight(root->right);
  res = max(res, lh + rh + 2);
  return 1 + max(lh, rh);
}

int getDiameter(TreeNode *root)
{
  getHeight(root);
  return res;
}

int main(int argc, char **argv)
{
//  TreeNode *root = new TreeNode(1, new TreeNode(2, new TreeNode(4), new TreeNode(5)), new TreeNode(3));
  TreeNode *root = new TreeNode(1, new TreeNode(2, new TreeNode(3, new TreeNode(5), 0), new TreeNode(4, 0, new TreeNode(6))), 0);
  int md = getDiameter(root);
  printf("%d\n", md);
  return 0;
}
