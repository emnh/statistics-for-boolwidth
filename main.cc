#include <iostream>
#include <vector>
#include <set>
#include <random>
#include <cstdlib>

using namespace std;

const int setSize = 10;
typedef unsigned long long TSet;

int computeNumberOfHoods(vector<TSet> startHoods) {
  set<TSet>& neighbourHoods = *(new set<TSet>());
  vector<TSet>& neighbourHoodsList = *(new vector<TSet>());

  // Push back the empty set
  neighbourHoods.insert(0);
  neighbourHoodsList.push_back(0);

  // Compute number of neighborhoods
  for (int i = 0; i < startHoods.size(); i++) {
    int sizeAtStart = neighbourHoodsList.size();
    for (int j = 0; j < sizeAtStart; j++) {
      TSet newHood = neighbourHoodsList[j] | startHoods[i];
      auto ret = neighbourHoods.insert(newHood);
      if (ret.second) {
        neighbourHoodsList.push_back(newHood);
      }
    }
  }

  return neighbourHoods.size();
}

int main() {
  vector<TSet>& startSets = *(new vector<TSet>());

	/* Seed */
  std::random_device rd;

  /* Random number generator */
  std::default_random_engine generator(rd());

  /* Distribution on which to apply the generator */
  //std::uniform_int_distribution<long long unsigned> distribution(0,0xFFFFFFFFFFFFFFFF);
  std::uniform_int_distribution<long long unsigned> distribution(0,0xFF);

  for (int i = 0; i < setSize; i++) {
    startSets.push_back(distribution(generator));
  }

  int hoods = computeNumberOfHoods(startSets);

  cerr << "Neighbourhoods: " << hoods << endl;
}
