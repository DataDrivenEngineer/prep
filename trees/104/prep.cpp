#include <stdio.h>
#include <algorithm>
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

void maxDepthRecursive(TreeNode* root, int& md, int d)
{
  if (root)
  {
    md = max(md, d);
    maxDepthRecursive(root->left, md, d + 1);
    maxDepthRecursive(root->right, md, d + 1);
  }
}

typedef struct
{
  TreeNode *r;
  int d;
} State;

int maxDepth(TreeNode* root)
{
  // recursive
//  int md = 0;
//  maxDepthRecursive(root, md, 1);
//  return md;

  // iterative
  int md = 0;
  stack<State> st;
  st.push({ root, 1 });
  while (!st.empty())
  {
    State s = st.top();
    st.pop();
    if (s.r)
    {
      md = max(md, s.d);
      st.push({s.r->left, s.d + 1});
      st.push({s.r->right, s.d + 1});
    }
  }
  return md;
}

int main(int argc, char **argv)
{
//  TreeNode *root = new TreeNode(2, new TreeNode(1), new TreeNode(3));
//  TreeNode *root = new TreeNode(3, new TreeNode(3), new TreeNode(20, new TreeNode(15), new TreeNode(7)));
  TreeNode *root = new TreeNode(1, 0, new TreeNode(2));
  int res = maxDepth(root);
  printf("%d\n", res);
  return 0;
}
