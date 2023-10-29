/*include your libraries here*/
#include <cassert>
#include <climits>
#include <cmath>
#include <iostream>

// BE SURE TO RENAME TO park_placement.cpp BEFORE SUBMITTING

using namespace std;

// This function should return the number of intersecting points between 2
// circles The 2 circles are defined by the function inputs

int NumIntersectPoints(int x1, int x2, int y1, int y2, int r1, int r2) {
  /*implement the function here*/
  int ret = 0;
  double dis = 0, rSum = 0, rDif = 0;
  rSum = abs(r1 + r2);
  rDif = abs(r1 - r2);
  dis = sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));
  // cocentric
  // 1. is at inf
  // 2. no is
  // non cocentric
  // 3. is at 2
  // 4. is at 1
  // 5. no is
  // 6. no is
  bool concentric = dis == 0;
  //cout << "conce:" << concentric<< "  rsum:" << rSum<<"  dis:" << dis<<"  rdiff:" << rDif <<"   ";
  if (concentric) {
    if (rDif == 0)
      ret = -1;
    else
      ret = 0;
  } else {
    if ((dis < rSum) && (dis > rDif))
      ret = 2;
    else if ((dis == rSum) || (dis == rDif))
      ret = 1;
    else
      ret = 0;
  }
  return ret;
}
int main() {
  // write your test cases here:
  // assert(NumIntersectPoints(30, 30, 60, 30, 10, 5) ==
  // 0);  // default one , no intersect
  // assert(NumIntersectPoints(30, 30, 30, 30, 10, 5) ==
  // 0);  // concentric , no intersect
  // assert(NumIntersectPoints(30, 30, 30, 20, 5, 5) == 1);  // one intersect
  // assert(NumIntersectPoints(30, 30, 16, 10, 5, 5) == 2);  // circle 1 is
  // below circle2, two intersects assert(NumIntersectPoints(30, 30, 30, 20, 10,
  // 5) == 2);  // circle 1 is above cicle 2, two intersects
  // assert(NumIntersectPoints(30, 30, 30, 30, 30, 30) ==
  // -1);  // same circle, inf intersects

  // call your function with specific inputs
  // check the output with assert statements
  int x1, y1, r1, x2, y2, r2;
  cin >> x1 >> x2 >> y1 >> y2 >> r1 >> r2;
  cout << NumIntersectPoints(x1, x2, y1, y2, r1, r2);
  return 0;
}
