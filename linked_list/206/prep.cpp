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

ListNode* reverseListIterative(ListNode* head)
{
  ListNode *curr = head;
  ListNode *prev = 0;
  while (curr != 0)
  {
    ListNode *tmp = curr->next;
    curr->next = prev;
    prev = curr;
    curr = tmp;
  }
  return prev;
}

ListNode* reverseListRecursive(ListNode* curr, ListNode *prev)
{
  if (curr == 0)
  {
    return prev;
  }
  ListNode *tmp = curr->next;
  curr->next = prev;
  prev = curr;
  return reverseListRecursive(tmp, prev);
}

ListNode* reverseList(ListNode* head)
{
  return reverseListRecursive(head, 0);
}

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
