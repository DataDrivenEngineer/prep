#include <stdio.h>

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

void printTree(TreeNode *root)
{
  if (root)
  {
    printf("%d ", root->val);
    printTree(root->left);
    printTree(root->right);
  }
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
{
  if (!root) return 0;
  int s;
  int l;
  if (p->val <= q->val)
  {
    s = p->val;
    l = q->val;
  }
  else
  {
    l = p->val;
    s = q->val;
  }
  if (root->val >= s && root->val <= l)
  {
    return root;
  }
  else if (root->val > s && root->val > l)
  {
    return lowestCommonAncestor(root->left, p, q);
  }
  else
  {
    return lowestCommonAncestor(root->right, p, q);
  }
}

int main(int argc, char **argv)
{
  TreeNode *q = new TreeNode(4, new TreeNode(3), new TreeNode(5));
  TreeNode *p = new TreeNode(2, new TreeNode(0), q);
  TreeNode *root = new TreeNode(6, p, new TreeNode(8, new TreeNode(7), new TreeNode(9)));
  TreeNode *res = lowestCommonAncestor(root, p, q);
  printf("%d\n", res->val);
  return 0;
}
