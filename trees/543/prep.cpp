#include <stdio.h>
#include <algorithm>

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

void diameterOfBinaryTreeRecursive(TreeNode* root, int& mp, int p)
{
  if (root)
  {
    if (root->left)
    {
      p++;
    }
    if (root->right)
    {
      p++;
    }
    mp = max(mp, p);
    diameterOfBinaryTreeRecursive(root->left, mp, p);
    diameterOfBinaryTreeRecursive(root->right, mp, p);
  }
}

int diameterOfBinaryTree(TreeNode* root)
{
  int mp = 0;
  diameterOfBinaryTreeRecursive(root, mp, 0);
  return mp;
}

int main(int argc, char **argv)
{
  TreeNode *root = new TreeNode(1, new TreeNode(2, new TreeNode(4), new TreeNode(5)), new TreeNode(3));
//  TreeNode *root = new TreeNode(4, new TreeNode(2, new TreeNode(1), new TreeNode(3)), 0);
  int res = diameterOfBinaryTree(root);
  printf("%d\n", res);
  return 0;
}
