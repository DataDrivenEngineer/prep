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

int main(int argc, char **argv)
{
  ListNode *head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5, 0)))));
  ListNode *res = reverseList(head);
  while (res != 0)
  {
    printf("%d ", res->val);
    res = res->next;
  }
  return 0;
}
