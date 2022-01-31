#include "solution.h"
#include <string>
#include <functional>

using namespace sol1273;
using namespace std;

/*takeaways
  - you construct the tree in a way that you can
    traverse it top-down from the root easily
  - peform a BFS traversal to decide which
    subtree should go
*/

/* C++ notes
   - use fully specified function if you need recursion:
     function<pair<int, int>(int)> visit = [&](int n)
   - know rvalue and destructuring
     auto [cSum, cNodes] = visit(child);
*/

int Solution::delTreeNodes(int nodes, vector<int> &parent, vector<int> &value)
{
  vector<vector<int>> tree(nodes);
  /*
    - construct the tree so it can be
      traversed top-down easily
    - skip the first element, which is the root
  */
  for (auto i = 1; i < nodes; ++i)
    /* add the children for node "parent[i]"" */
    tree[parent[i]].push_back(i);

  /*
    - return sum and number of nodes
      for a sub-tree
  */

  /* C++ notes
     - you need a fully specified function
       for recursion.
     - you can't use auto or you will run
       into type deduction error when
       compiling the code
  */

  function<pair<int, int>(int)> visit = [&](int n)
  {
    /* the node we are visiting */
    int sum = value[n];
    int nodes = 1;

    /*
      - do a BFS search
      - tree[n] has the child nodes for
        the node we are visiting
    */
    for (int child : tree[n])
    {
      auto [cSum, cNodes] = visit(child);
      sum += cSum;
      nodes += cNodes;
    }
    /*
      - if the sum is zero we just report
        back 0 nodes for this subtree,
        which is the same as deleting
        the subtree by just not counting
        it
      - this also covers the leaf node
        where its value is zero
    */
    return make_pair(sum, sum ? nodes : 0);
  };

  /* kick off the traversal */
  return visit(0).second;
}