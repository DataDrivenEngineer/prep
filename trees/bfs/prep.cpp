#include <stdio.h>
#include <deque>

using namespace std;

struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int val): val(val), left(0), right(0) {}
  TreeNode(int val, TreeNode *l, TreeNode *r): val(val), left(l), right(r) {}
};

void bfs(TreeNode *root)
{
  deque<TreeNode *> dq;
  dq.push_back(root);
  while (!dq.empty())
  {
    TreeNode * curr = dq.front();
    printf("%d ", curr->val);
    dq.pop_front();
    if (curr->left)
    {
      dq.push_back(curr->left);
    }
    if (curr->right)
    {
      dq.push_back(curr->right);
    }
  }
}

int main(int argc, char **argv)
{
  TreeNode *root = new TreeNode(1, new TreeNode(4, 0, new TreeNode(3, new TreeNode(7), new TreeNode(2))), new TreeNode(5, 0, new TreeNode(9)));
  bfs(root);
  // expected printout: 1 4 5 3 9 7 2
  return 0;
}
