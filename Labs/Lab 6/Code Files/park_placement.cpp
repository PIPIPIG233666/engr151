/*include your libraries here*/
#include <cassert>
#include <climits>
#include <cmath>
#include <cstdio>

// BE SURE TO RENAME TO park_placement.cpp BEFORE SUBMITTING

using namespace std;

// This function should return the number of intersecting points between 2
// circles The 2 circles are defined by the function inputs

int NumIntersectPoints(int x1, int x2, int y1, int y2, int r1, int r2) {
  /*implement the function here*/
  int ret = 0;
  int dis = 0;
  int rSum = 0;
  rSum = r1 + r2;
  dis = sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));
  if (rSum > dis)
    ret = 2;
  else if (rSum == dis)
    ret = 1;
  if (dis == 0) {
    if (r1 == r2)
      ret = INT_MAX;
    else
      ret = 0;
  }
  return ret;
}

int main() {
  // write your test cases here:
  // call your function with specific inputs
  // check the output with assert statements
  assert(NumIntersectPoints(30, 30, 60, 30, 10, 5) ==
         0);  // default one , no intersect
  assert(NumIntersectPoints(30, 30, 30, 30, 10, 5) ==
         0);  // concentric , no intersect
  assert(NumIntersectPoints(30, 30, 30, 20, 5, 5) == 1);  // one intersect
  assert(NumIntersectPoints(30, 30, 16, 10, 5, 5) == 2);  // circle 1 is below circle2, two intersects
  assert(NumIntersectPoints(30, 30, 30, 20, 10, 5) == 2);  // circle 1 is above cicle 2, two intersects
  assert(NumIntersectPoints(30, 30, 30, 30, 30, 30) ==
         INT_MAX);  // same circle, inf intersects
  return 0;
}
