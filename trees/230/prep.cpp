#include <stdio.h>
#include <vector>
#include <queue>

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

void inOrderWithoutHeap(TreeNode *root, vector<int>& v)
{
  if (root)
  {
    inOrderWithoutHeap(root->left, v);
    v.push_back(root->val);
    inOrderWithoutHeap(root->right, v);
  }
}

void inOrderWithHeap(TreeNode *root, priority_queue<int, vector<int>, greater<int>>& pq)
{
  if (root)
  {
    inOrderWithHeap(root->left, pq);
    pq.push(root->val);
    inOrderWithHeap(root->right, pq);
  }
}

int kthSmallest(TreeNode* root, int k)
{
  // without binary heap
//  vector<int> v;
//  inOrder(root, v);
//  return v[k - 1];

  // with binary heap
  priority_queue<int, vector<int>, greater<int>> pq;
  inOrderWithHeap(root, pq);
  for (int i = 0; i < k - 1; i++)
  {
    pq.pop();
  }
  return pq.top();
}

int main(int argc, char **argv)
{
//  TreeNode *root = new TreeNode(3, new TreeNode(1, 0, new TreeNode(2)), new TreeNode(4));
//  int k = 1;
  TreeNode *root = new TreeNode(5, new TreeNode(3, new TreeNode(2, new TreeNode(1), 0), new TreeNode(4)), new TreeNode(6));
  int k = 3;
  int res = kthSmallest(root, k);
  printf("%d\n", res);
  return 0;
}
