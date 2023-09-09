#include <stdio.h>
#include <unordered_set>

using namespace std;

struct ListNode
{
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

bool hasCycle(ListNode *head)
{
  ListNode *curr = new ListNode(0, head);
  unordered_set<ListNode *> s;
  while (curr->next)
  {
    curr = curr->next;
    if (s.count(curr))
    {
      return true;
    }
    s.insert(curr);
  }
  return false;
}

bool hasCycleConstantSpaceRecursive(ListNode *s, ListNode *f)
{
  if (f && f->next)
  {
    s = s->next;
    f = f->next->next;
    if (s == f)
    {
      return true;
    }
    return hasCycleConstantSpaceRecursive(s, f);
  }
  return false;
}

bool hasCycleConstantSpaceIterative(ListNode *head)
{
  ListNode *s = new ListNode(0, head);
  ListNode *f = s;
  while (f && f->next)
  {
    s = s->next;
    f = f->next->next;
    if (s == f)
    {
      return true;
    }
  }
  return false;
}

bool hasCycleConstantSpace(ListNode *head)
{
  ListNode *s = new ListNode(0, head);
  ListNode *f = s;
  return hasCycleConstantSpaceRecursive(s, f);
}

int main(int argc, char **argv)
{
  ListNode *one = new ListNode(3);
  ListNode *two = new ListNode(2);
  ListNode *three = new ListNode(0);
  ListNode *four = new ListNode(-4);
  one->next = two;
  two->next = three;
  three->next = four;
  four->next = two;
//  bool res = hasCycle(one);
  bool res = hasCycleConstantSpace(one);
  printf("%d\n", res);
  return 0;
}
