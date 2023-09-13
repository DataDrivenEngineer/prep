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

static bool eq = true;

void dfs(TreeNode *p, TreeNode *q)
{
  if (p && q)
  {
    if (p->val != q->val)
    {
      eq = false;
    }
    dfs(p->left, q->left);
    dfs(p->right, q->right);
  }
  else if (p || q)
  {
    eq = false;
  }
}

bool areEqual(TreeNode *p, TreeNode *q)
{
  dfs(p, q);
  return eq;
}

int main(int argc, char **argv)
{
//  TreeNode *p = new TreeNode(1, new TreeNode(2), new TreeNode(3));
//  TreeNode *q = new TreeNode(1, new TreeNode(2), new TreeNode(3));
//  TreeNode *p = new TreeNode(1, new TreeNode(2), 0);
//  TreeNode *q = new TreeNode(1, 0, new TreeNode(2));
  TreeNode *p = new TreeNode(1, new TreeNode(2), new TreeNode(1));
  TreeNode *q = new TreeNode(1, new TreeNode(1), new TreeNode(2));
  bool res = areEqual(p, q);
  printf("%d\n", res);
  return 0;
}
