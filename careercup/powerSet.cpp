//
/*
8.4 Power Set: Write a method to return all subsets of a set.
SOLUTION
We should first have some reasonable expectations of our time and space
complexity.
pg 135
How many subsets of a set are there? When we generate a subset, each element has
the "choice" of either
being in there or not. That is, for the first element, there are two choices: it
is either in the set or it is not. For
the second, there are two, etc. So, doing { 2 * 2 * . . . } n times gives us 2"
subsets.
Assuming that we're going to be returning a list of subsets, then our best case
time is actually the total
number of elements across all of those subsets. There are 2" subsets and each of
the n elements will be
contained in half of the subsets (which 2n- 1 subsets). Therefore, the total
number of elements across all of
those subsets is n * 2n-1.
We will not be able to beat 0( n2") in space or time complexity.
The subsets of {a1 , a2 , ••• , an} are also called the powersetP({a1, a2 , •••
, an}),orjustP(n).
Solution #1: Recursion
This problem is a good candidate for the Base Case and Build approach. Imagine
that we are trying to find
all subsets of a set like S = {a 1, a 2, ••• , an}. We can start with the Base
Case.
Base Case: n = 0.
There is just one subset of the empty set: {}.
Case:n = 1.
There are two subsets of the set {aJ: {}, {aJ.
Case:n = 2.
There are four subsets of the set {a 1
, aJ: {}, {aJ, {a), {a1
, a 2}.
Case:n = 3.
Now here's where things get interesting. We want to find a way of generating the
solution for n
on the prior solutions.
3 based
What is the difference between the solution for n 3 and the solution for n = 2?
Let's look at this more
deeply:
P(2) = {}, {a1}, {a2}, {a1
, a2}
P(3) = {}, {aJ, {a2}, {a 3}, {a1, a2}, {a 1, a 3}, {a2, a3}, {a 1, a 2, a3}
The difference between these solutions is that P ( 2) is missing all the subsets
containing a 3•
P(3) - P(2) = {a3}, {a1 , a3 }, {a 2, a 3}, {a1, a2, a3}
How can we use P ( 2) to create P ( 3)? We can simply clone the subsets in P (
2) and add a3 to them:
P(2) {} , {a 1
}, {a2
}, {a1, aJ
P(2) + a, = {a 3}, {a1, a3}, {a2 , a), {a1, a2, a 3}
When merged together, the lines above make P ( 3).
Case:n > 0
Generating P ( n) for the general case is just a simple generalization of the
above steps. We compute
P ( n-1), clone the results, and then add a n to each of these cloned sets.
The following code implements this algorithm:
1 Arraylist<Arraylist<Integer>> getSubsets(Arraylist<Integer> set, int index) {
2 Arraylist<Arraylist<Integer>> allsubsets;
3 if (set.size()== index) {//Base case - add empty set
4 allsubsets = new Arraylist<Arraylist<Integer>>();
5 allsubsets.add(new Arraylist<Integer>()); // Empty set
6 } else {
7 allsubsets = getSubsets(set, index+ 1);
8 int item= set.get(index);
9 Arraylist<Arraylist<Integer>> moresubsets
10 new Arraylist<Arraylist<Integer>>();
11 for (Arraylist<Integer> subset : allsubsets) {
12 Arraylist<Integer> newsubset = new Arraylist<Integer>();
13 newsubset.addAll(subset); //
14 newsubset.add(item);
15 moresubsets.add(newsubset);
16 }
17 allsubsets.addAll(moresubsets);
18 }
19 return allsubsets;
20 }
This solution will be O(n2n) in time and space, which is the best we can do. For
a slight optimization, we
could also implement this algorithm iteratively.
*/

#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<int>> sets;
vector<vector<int>> getSubsets(vector<int> set, int index) {
  sets allSubsets;
  if (index == set.size()) {
    vector<int> empty = {};
    allSubsets.push_back(empty);
  } else {
    allSubsets = getSubsets(set, index + 1);
    int item = set[index];
    sets moreSubsets;
    for (auto subset : allSubsets) {
      vector<int> newSubset;
      newSubset = subset;
      newSubset.push_back(item);
      moreSubsets.push_back(newSubset);
    }
    allSubsets.insert(allSubsets.end(), moreSubsets.begin(), moreSubsets.end());
  }
  return allSubsets;
}

int main() {
  vector<int> set = {1, 2, 3};
  sets allSubsets = getSubsets(set, 0);
  for (auto x : allSubsets) {
    for (auto y : x) {
      cout << y << " ";
    }
    cout << endl;
  }
  return 0;
}
