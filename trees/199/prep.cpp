#include <stdio.h>
#include <vector>
#include <deque>

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

typedef struct
{
  TreeNode *n;
  int i;
} State;

vector<int> rightSideView(TreeNode* root)
{
  vector<int> out;
  if (!root) return out;
  deque<State> d;
  d.push_back({ root, 0 });
  while (!d.empty())
  {
    State s = d.front();
    d.pop_front();
    if (s.i > (int) (out.size() - 1))
    {
      out.push_back(s.n->val);
    }
    else
    {
      out[s.i] = s.n->val;
    }
    if (s.n->left)
    {
      d.push_back({ s.n->left, s.i + 1 });
    }
    if (s.n->right)
    {
      d.push_back({ s.n->right, s.i + 1 });
    }
  }
  return out;
}

int main(int argc, char **argv)
{
  TreeNode *root = new TreeNode(1, new TreeNode(2, 0, new TreeNode(5)), new TreeNode(3, 0, new TreeNode(4)));
  vector<int> res = rightSideView(root);
  for (const auto& n : res)
  {
    printf("%d ", n);
  }
  return 0;
}
