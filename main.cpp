#include <iostream>
#include "solution.h"

using namespace std;
using namespace sol1273;
/*
  Input: nodes = 7, parent = [-1,0,0,1,2,2,2], value = [1,-2,4,0,-2,-1,-1]
  Output: 2
*/

pair<vector<int>, vector<int>> testFixture1()
{
  vector<int> parent = {-1, 0, 0, 1, 2, 2, 2};
  vector<int> value = {1, -2, 4, 0, -2, -1, -1};
  return make_pair(parent, value);
}

void test1()
{
  auto fixture = testFixture1();
  auto parent = fixture.first;
  auto value = fixture.second;
  Solution sol;
  cout << "Test 1 - expect to see 2" << endl;
  cout << "result: " << sol.delTreeNodes(7, parent, value);
}

main()
{
  test1();
}