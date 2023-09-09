#include <stdio.h>
#include <limits.h>

using namespace std;

struct ListNode
{
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* mergeTwoListsIterative(ListNode* list1, ListNode* list2)
{
  ListNode *res = new ListNode();
  ListNode *head = res;
  while (list1 && list2)
  {
    if (list1->val < list2->val)
    {
      res->next = list1;
      list1 = list1->next;
    }
    else
    {
      res->next = list2;
      list2 = list2->next;
    }
    res = res->next;
  }
  if (list1)
  {
    res->next = list1;
  }
  if (list2)
  {
    res->next = list2;
  }
  return head->next;
}

ListNode* mergeTwoListsRecursive(ListNode *head, ListNode* res, ListNode* list1, ListNode* list2)
{
  if (!list1 && !list2)
  {
    return head->next;
  }
  if (list1 && list2)
  {
    if (list1->val < list2->val)
    {
      res->next = list1;
      list1 = list1->next;
    }
    else
    {
      res->next = list2;
      list2 = list2->next;
    }
    return mergeTwoListsRecursive(head, res->next, list1, list2);
  }
  else if (list1)
  {
    res->next = list1;
    return mergeTwoListsRecursive(head, 0, 0, 0);
  }
  else
  {
    res->next = list2;
    return mergeTwoListsRecursive(head, 0, 0, 0);
  }
}


ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
{
  ListNode *res = new ListNode();
  ListNode *head = res;
  return mergeTwoListsRecursive(head, res, list1, list2);
}

int main(int argc, char **argv)
{
  ListNode *l1 = new ListNode(1, new ListNode(2, new ListNode(4, 0)));
  ListNode *l2 = new ListNode(1, new ListNode(3, new ListNode(4, 0)));
  ListNode *res = mergeTwoLists(l1, l2);
  while (res != 0)
  {
    printf("%d ", res->val);
    res = res->next;
  }
  return 0;
}
