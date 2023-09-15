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

int dfs(TreeNode *root, int max)
{
  if (!root) return 0;
  if (root->val >= max)
  {
    max = root->val;
    return 1 + dfs(root->left, max) + dfs(root->right, max);
  }
  else
  {
    return dfs(root->left, max) + dfs(root->right, max);
  }
}

int goodNodesRecursive(TreeNode* root)
{
  if (!root) return 0;
  int gl = dfs(root->left, root->val);
  int gr = dfs(root->right, root->val);
  return 1 + gl + gr;
}

typedef struct
{
  TreeNode *root;
  int max;
} State;

int goodNodes(TreeNode* root)
{
  // recursive
//  return goodNodesRecursive(root);

  // iterative
  if (!root) return 0;
  int res = 1;
  stack<State> st;
  st.push({ root->left, root->val });
  st.push({ root->right, root->val });
  while (!st.empty())
  {
    State s = st.top();
    st.pop();
    if (!s.root) continue;
    if (s.root->val >= s.max)
    {
      s.max = s.root->val;
      res += 1; 
      st.push({ s.root->left, s.max });
      st.push({ s.root->right, s.max });
    }
    else
    {
      st.push({ s.root->left, s.max });
      st.push({ s.root->right, s.max });
    }
  }
  return res;
}

int main(int argc, char **argv)
{
  TreeNode *root = new TreeNode(3, new TreeNode(1, new TreeNode(3), 0), new TreeNode(4, new TreeNode(1), new TreeNode(5)));
  int res = goodNodes(root);
  printf("%d\n", res);
  return 0;
}
