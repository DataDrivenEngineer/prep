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

vector<vector<int>> levelOrder(TreeNode* root)
{
  vector<vector<int>> out;
  if (!root) return out;
  deque<State> d;
  d.push_back({ root, 0 });
  while (!d.empty())
  {
    State s = d.front();
    d.pop_front();
    if (s.i > (int) (out.size() - 1))
    {
      out.emplace_back(1, s.n->val);
    }
    else
    {
      out[s.i].push_back(s.n->val);
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
  TreeNode *root = new TreeNode(3, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7)));
  vector<vector<int>> res = levelOrder(root);
  for (const auto& v : res)
  {
    for (const auto& num : v)
    {
      printf("%d ", num);
    }
    printf("\n");
  }
  return 0;
}
