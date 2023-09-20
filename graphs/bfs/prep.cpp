#include <stdio.h>
#include <deque>
#include <vector>
#include <unordered_set>

using namespace std;

struct Node
{
  int val;
  vector<Node *> neighbours;
  Node(int x): val(x), neighbours() {}
  Node(int x, vector<Node *> n): val(x), neighbours(n) {}
};

void bfs(Node *n)
{
  deque<Node *> dq;
  unordered_set<Node *> s;
  dq.push_back(n);
  while (!dq.empty())
  {
    Node *cn = dq.front();
    dq.pop_front();
    if (!s.count(cn))
    {
      s.insert(cn);
      printf("%d ", cn->val);
      for (auto& nei : cn->neighbours)
      {
	dq.push_back(nei);
      }
    }
  }
}

int main(int argc, char **argv)
{
  Node *n1 = new Node(1);
  Node *n2 = new Node(2);
  Node *n3 = new Node(3);
  Node *n4 = new Node(4);
  Node *n5 = new Node(5);
  Node *n6 = new Node(6);
  Node *n7 = new Node(7);
  Node *n8 = new Node(8);
  Node *n9 = new Node(9);

  n1->neighbours = { n2, n4 };
  n2->neighbours = { n1, n3, n5 };
  n3->neighbours = { n2, n6 };
  n4->neighbours = { n1, n5, n7 };
  n5->neighbours = { n2, n4, n6, n8 };
  n6->neighbours = { n3, n5, n9 };
  n7->neighbours = { n8, n4 };
  n8->neighbours = { n7, n5, n9 };
  n9->neighbours = { n6, n8 };

  bfs(n1);
  return 0;
}
