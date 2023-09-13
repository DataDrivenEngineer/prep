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

static bool res = false;
static bool eq = true;

void areEqualDfs(TreeNode *p, TreeNode *q)
{
  if (p && q)
  {
    if (p->val != q->val)
    {
      eq = false;
    }
    areEqualDfs(p->left, q->left);
    areEqualDfs(p->right, q->right);
  }
  else if (p || q)
  {
    eq = false;
  }
}

bool areEqual(TreeNode *p, TreeNode *q)
{
  areEqualDfs(p, q);
  bool oldEq = eq;
  eq = true;
  return oldEq;
}

void dfs(TreeNode *p, TreeNode *q)
{
  if (p && q)
  {
    bool isSame = areEqual(p, q);
    if (isSame)
    {
      res = true;
    }
    dfs(p->left, q);
    dfs(p->right, q);
  }
  else if (!p && !q)
  {
    res = true;
  }
}

bool isSubtree(TreeNode *p, TreeNode *q)
{
  dfs(p, q);
  return res;
}

int main(int argc, char **argv)
{
//  TreeNode *p = new TreeNode(3, new TreeNode(4, new TreeNode(1), new TreeNode(2)), new TreeNode(5));
//  TreeNode *q = new TreeNode(4, new TreeNode(1), new TreeNode(2));
  TreeNode *p = new TreeNode(3, new TreeNode(4, new TreeNode(1), new TreeNode(2, new TreeNode(0), 0)), new TreeNode(5));
  TreeNode *q = new TreeNode(4, new TreeNode(1), new TreeNode(2));
  bool res = isSubtree(p, q);
  printf("%d\n", res);
  return 0;
}
