#include <stdio.h>
#include <vector>

using namespace std;

int main(int argc, char **argv)
{
  vector<int> v = { 1,2,3,4,5 };

  // prints '1'
//  vector<int> nv = vector<int>(v.begin(), v.begin() + 1);
//  for (const auto& n : nv)
//  {
//    printf("%d ", n);
//  }

  // exception thrown
//  vector<int> nv = vector<int>(v.begin() + 2, v.begin() + 1);
//  for (const auto& n : nv)
//  {
//    printf("%d ", n);
//  }

  // empty vector - nothing is printed
  vector<int> nv = vector<int>(v.begin() + 2, v.begin() + 2);
  for (const auto& n : nv)
  {
    printf("%d ", n);
  }

  printf("\n");
  return 0;
}
