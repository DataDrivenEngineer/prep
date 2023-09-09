#include <stdio.h>
#include <unordered_map>

using namespace std;

class LRUCache
{
private:
  struct ListNode
  {
    int key;
    int val;
    ListNode *next;
    ListNode *prev;
    ListNode() : key(0), val(0), next(nullptr), prev(0) {}
    ListNode(int k, int x) : key(k), val(x), next(nullptr), prev(0) {}
    ListNode(int k, int x, ListNode *next, ListNode *prev) : key(k), val(x), next(next), prev(prev) {}
  };

  int c;
  int s;
  ListNode *head;
  ListNode *tail;
  unordered_map<int, ListNode *> m;
public:
  LRUCache(int capacity): c(capacity), s(0), head(0), tail(0), m()
  {
    head = new ListNode(0, 0, 0, 0);
    tail = new ListNode(0, 0, 0, head);
    head->next = tail;
  }
  void print()
  {
    ListNode *curr = head;
    while (curr)
    {
      printf("key: %d, value: %d ", curr->key, curr->val);
      curr = curr->next;
    }
    printf("\n");
  }

  ListNode * _get(int key)
  {
    auto it = m.find(key);
    if (it != m.end())
    {
      ListNode *curr = it->second;
      ListNode *headNxt = head->next;
      if (curr == headNxt)
      {
	return curr;
      }
      ListNode *currNxt = curr->next;
      ListNode *currPrv = curr->prev;
      head->next = curr;
      curr->next = headNxt;
      headNxt->prev = curr;
      curr->prev = head;
      currPrv->next = currNxt;
      currNxt->prev = currPrv;
      return curr;
    }
    return 0;
  }
  int get(int key)
  {
    ListNode *got = _get(key);
    if (got)
    {
      return got->val;
    }
    else
    {
      return -1;
    }
  }
  void put(int key, int value)
  {
    ListNode *got = _get(key);
    if (!got)
    {
      ListNode *headNxt = head->next;
      head->next = new ListNode(key, value, headNxt, head);
      headNxt->prev = head->next;
      m[key] = head->next;
      if (s == c)
      {
	m.erase(tail->prev->key);
	tail->prev->prev->next = tail;
	tail->prev = tail->prev->prev;
      }
      else
      {
	s++;
      }
    }
    else
    {
      got->val = value;
    }
  }
};

int main(int argc, char **argv)
{
  LRUCache lRUCache = LRUCache(2);
  lRUCache.put(1, 1); // cache is {1=1}
  lRUCache.put(2, 2); // cache is {1=1, 2=2}
  printf("%d\n", lRUCache.get(1));   // return 1
  lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
  printf("%d\n", lRUCache.get(2));   // returns -1 (not found)
  lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
  printf("%d\n", lRUCache.get(1));   // return -1 (not found)
  printf("%d\n", lRUCache.get(3));
  printf("%d\n", lRUCache.get(4));
//  LRUCache lRUCache = LRUCache(1);
//  lRUCache.put(2, 1); 
//  lRUCache.print();
//  printf("%d\n", lRUCache.get(2));   
//  lRUCache.print();
//  lRUCache.put(3, 2); 
//  lRUCache.print();
//  printf("%d\n", lRUCache.get(2));   
//  printf("%d\n", lRUCache.get(3));   
  return 0;
}
