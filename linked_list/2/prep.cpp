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

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
  ListNode *c1 = new ListNode(0, l1);
  ListNode *c2 = new ListNode(0, l2);
  ListNode *l3 = new ListNode();
  ListNode *c3 = l3;
  int remainder = 0;
  while (c1->next && c2->next)
  {
    c1 = c1->next;
    c2 = c2->next;
    c3->next = new ListNode();
    c3 = c3->next;
    int sum = c1->val + c2->val + remainder;
    if (sum > 9)
    {
      remainder = 1;
      c3->val = sum - 10;
    }
    else
    {
      remainder = 0;
      c3->val = sum;
    }
  }
  while (c1->next)
  {
    c1 = c1->next;
    if (remainder > 0)
    {
      c3->next = new ListNode();
      c3 = c3->next;
      int sum = c1->val + remainder;
      if (sum > 9)
      {
	remainder = 1;
	c3->val = sum - 10;
      }
      else
      {
	remainder = 0;
	c3->val = sum;
      }
    }
    else
    {
      c3->next = c1;
      break;
    }
  }
  while (c2->next)
  {
    c2 = c2->next;
    if (remainder > 0)
    {
      c3->next = new ListNode();
      c3 = c3->next;
      int sum = c2->val + remainder;
      if (sum > 9)
      {
	remainder = 1;
	c3->val = sum - 10;
      }
      else
      {
	remainder = 0;
	c3->val = sum;
      }
    }
    else
    {
      c3->next = c2;
      break;
    }
  }
  if (remainder > 0)
  {
    c3->next = new ListNode(1, 0);
  }
  return l3->next;
}

int main(int argc, char **argv)
{
//  ListNode *l1 = new ListNode(2, new ListNode(4, new ListNode(3, 0)));
//  ListNode *l2 = new ListNode(5, new ListNode(6, new ListNode(4, 0)));
  ListNode *l1 = new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode (9, new ListNode (9, 0)))))));
  ListNode *l2 = new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9, 0))));
  ListNode *res = addTwoNumbers(l1, l2);
  while (res != 0)
  {
    printf("%d ", res->val);
    res = res->next;
  }
  return 0;
}
