#include <stdio.h>
#include <vector>

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

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
{
  if (!preorder.size() || !inorder.size()) return 0;
  TreeNode *root = new TreeNode(preorder[0]);
  int mid = 0;
  while (inorder[mid] != preorder[0])
  {
    mid++;
  }
  vector<int> lp = vector<int>(preorder.begin() + 1, preorder.begin() + mid + 1);
  vector<int> li = vector<int>(inorder.begin(), inorder.begin() + mid);
  TreeNode *left = buildTree(lp, li);
  vector<int> rp = vector<int>(preorder.begin() + mid + 1, preorder.end());
  vector<int> ri = vector<int>(inorder.begin() + mid + 1, inorder.end());
  TreeNode *right = buildTree(rp, ri);
  root->left = left;
  root->right = right;
  return root;
}

int main(int argc, char **argv)
{
  vector<int> preorder = { 3, 9, 20, 15, 7 };
  vector<int> inorder = { 9, 3, 15, 20, 7 };
  TreeNode *res = buildTree(preorder, inorder);
  printTree(res);
  return 0;
}
