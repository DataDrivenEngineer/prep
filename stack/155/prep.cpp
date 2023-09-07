#include <stdio.h>
#include <limits.h>

using namespace std;

#define MAX_SIZE 30000

class MinStack
{
private:
  int data[MAX_SIZE];
  int minData[MAX_SIZE];
  int topIndex;
  int min;
public:
  MinStack()
  : topIndex(-1),
    min(INT_MAX)
  {
  }
  ~MinStack() = default;
  void push(int v)
  {
    topIndex++;
    data[topIndex] = v;
    if (v < min)
    {
      min = v;
    }
    minData[topIndex] = min;
  }
  void pop()
  {
    topIndex--;
  }
  int top()
  {
    return data[topIndex];
  }
  int getMin() { return minData[topIndex]; }
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
