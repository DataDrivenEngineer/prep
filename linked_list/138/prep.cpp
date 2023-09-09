#include <stdio.h>
#include <unordered_map>

using namespace std;

class Node
{
public:
  int val;
  Node* next;
  Node* random;
  
  Node(int _val) {
    val = _val;
    next = NULL;
    random = NULL;
  }
};

Node *copyRandomListIterative(Node *head)
{
  if (!head) return 0;

  unordered_map<Node *, Node *> m;
  Node *newHead = new Node(head->val);
  Node *co = head;
  Node *cn = newHead;
  m[head] = newHead;
  m[0] = 0;
  while (co)
  {
    const auto& itn = m.find(co->next);
    if (itn == m.end())
    {
      m[co->next] = new Node(co->next->val);
    }
    const auto& itr = m.find(co->random);
    if (itr == m.end())
    {
      m[co->random] = new Node(co->random->val);
    }
    cn->next = m[co->next];
    cn->random = m[co->random];
    co = co->next;
    cn = cn->next;
  }
  return newHead;
}

Node *copyRandomListRecursive(unordered_map<Node *, Node *>& m, Node *newHead, Node *co, Node *cn)
{
  if (!co)
  {
    return newHead;
  }
  const auto& itn = m.find(co->next);
  if (itn == m.end())
  {
    m[co->next] = new Node(co->next->val);
  }
  const auto& itr = m.find(co->random);
  if (itr == m.end())
  {
    m[co->random] = new Node(co->random->val);
  }
  cn->next = m[co->next];
  cn->random = m[co->random];
  return copyRandomListRecursive(m, newHead, co->next, cn->next);
}

Node *copyRandomList(Node *head)
{
  // recursive
//  if (!head) return 0;
//
//  unordered_map<Node *, Node *> m;
//  Node *newHead = new Node(head->val);
//  Node *co = head;
//  Node *cn = newHead;
//  m[head] = newHead;
//  m[0] = 0;
//  return copyRandomListRecursive(m, newHead, co, cn);

  // iterative
  return copyRandomListIterative(head);
}

int main(int argc, char **argv)
{
  Node * four = new Node(1);
  four->next = 0;

  Node * three = new Node(10);
  three->next = four;

  Node * two = new Node(11);
  two->next = three;
  two->random = four;

  three->random = two;

  Node * zero = new Node(7);
  zero->random = 0;

  Node * one = new Node(13);
  one->next = two;
  one->random = zero;

  zero->next = one;
  four->random = zero;

  Node *res = copyRandomList(zero);
  while (res != 0)
  {
    printf("%d ", res->val);
    res = res->next;
  }
  return 0;
}
