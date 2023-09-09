#include <stdio.h>

using namespace std;

struct ListNode
{
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void reorderList(ListNode*& head)
{
  // find start of second list
  ListNode *s = head;
  ListNode *f = head;
  while (f)
  {
    if (!f->next)
    {
      break;
    }
    s = s->next;
    f = f->next->next;
  }
  // reverse links of second list
  ListNode *prev = 0;
  while (s)
  {
    ListNode *n = s->next;
    s->next = prev;
    prev = s;
    s = n;
  }
  // prev = head of inverted list (i.e. last element)
  // merge lists
  ListNode *l = head;
  ListNode *r = prev;
  while (l && l < r && l->next != r)
  {
    ListNode *lNxt = l->next;
    ListNode *rNxt = r->next;
    l->next = r;
    r->next = lNxt;
    r = rNxt;
    l = l->next->next;
  }
}

int main(int argc, char **argv)
{
//  ListNode *res = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, 0))));
  ListNode *res = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5, 0)))));
  reorderList(res);
  while (res != 0)
  {
    printf("%d ", res->val);
    res = res->next;
  }
  return 0;
}
