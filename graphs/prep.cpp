#include <stdio.h>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Node {
public:
  int val;
  vector<Node*> neighbors;
  Node() {
    val = 0;
    neighbors = vector<Node*>();
  }
  Node(int _val) {
    val = _val;
    neighbors = vector<Node*>();
  }
  Node(int _val, vector<Node*> _neighbors) {
    val = _val;
    neighbors = _neighbors;
  }
};

void print(Node *n, unordered_set<Node *>& seen)
{
  if (!seen.count(n))
  {
    seen.insert(n);
    printf("%d ", n->val);
    for (auto& nb : n->neighbors)
    {
      print(nb, seen);
    }
  }
}

int main(int argc, char **argv)
{
  Node *n1 = new Node(1);
  Node *n2 = new Node(2);
  Node *n3 = new Node(3);
  Node *n4 = new Node(4);
  n1->neighbors = { n2, n4 };
  n2->neighbors = { n1, n3 };
  n3->neighbors = {n2, n4};
  n4->neighbors = {n1, n3};

  unordered_set<Node *> seen;
  print(n1, seen);
  return 0;
}
