#include <stdio.h>
#include <vector>

using namespace std;

#define MAX_STACK_SIZE 30000

class MinStack
{
private:
  vector<int> values;
  vector<int> mins;

public:
  MinStack()
  {
    values.reserve(MAX_STACK_SIZE);
    mins.reserve(MAX_STACK_SIZE);
  }

  void push(int val)
  {
    if (values.size() == 0 || *(mins.end() - 1) > val)
    {
      mins.push_back(val);
    }
    else
    {
      mins.push_back(*(mins.end() - 1));
    }

    values.push_back(val);
  }

  void pop()
  {
    values.pop_back();
    mins.pop_back();
  }

  int top()
  {
    return *(values.end() - 1);
  }

  int getMin()
  {
    return *(mins.end() - 1);
  }
};

int main(int argc, char **argv)
{
  MinStack minStack = MinStack();
  minStack.push(-2);
  minStack.push(0);
  minStack.push(-3);
  printf("%d\n", minStack.getMin());
  minStack.pop();
  printf("%d\n", minStack.top());
  printf("%d\n", minStack.getMin());
  return 0;
}
