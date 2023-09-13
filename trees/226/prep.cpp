#include <stdio.h>
#include <stack>

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

void invertTreeRecursively(TreeNode* root)
{
  if (root)
  {
    TreeNode *tmp = root->right;
    root->right = root->left;
    root->left = tmp;
    invertTreeRecursively(root->left);
    invertTreeRecursively(root->right);
  }
}

void invertTreeIteratively(TreeNode *root)
{
  stack<TreeNode *> st;
  st.push(root);
  while (!st.empty())
  {
    TreeNode * r = st.top();
    st.pop();
    if (r)
    {
      TreeNode *tmp = r->right;
      r->right = r->left;
      r->left = tmp;
      st.push(r->left);
      st.push(r->right);
    }
  }
}

TreeNode* invertTree(TreeNode* root)
{
//  invertTreeRecursively(root);
  invertTreeIteratively(root);
  return root;
}

int main(int argc, char **argv)
{
  TreeNode root = TreeNode(2, new TreeNode(1), new TreeNode(3));
  TreeNode *res = invertTree(&root);
  printTree(res);
  return 0;
}
