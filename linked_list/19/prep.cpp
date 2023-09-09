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

ListNode* removeNthFromEnd(ListNode* head, int n)
{
  if (!head) return 0;
  int count = 1;
  ListNode * curr = head;
  while (curr)
  {
    count++;
    curr = curr->next;
  }
  curr = head;
  ListNode *prev = 0;
  int runningCount = 1;
  while (curr)
  {
    runningCount++;
    if (runningCount == count - n + 1)
    {
      if (curr == head)
      {
	head = head->next;
      }
      else
      {
	prev->next = curr->next;
      }
      break;
    }
    prev = curr;
    curr = curr->next;
  }
  return head;
}

int main(int argc, char **argv)
{
  ListNode *l1 = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5, 0)))));
  int n = 2;
  ListNode *res = removeNthFromEnd(l1, 2);
  while (res != 0)
  {
    printf("%d ", res->val);
    res = res->next;
  }
  return 0;
}
