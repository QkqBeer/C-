#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class RandomizedSet {
public:
	/** Initialize your data structure here. */
	RandomizedSet() {

	}

	/** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
	bool insert(int val) {
		if (hash.count(val) == 1) return false;
		hash[val] = vec.size();
		vec.push_back(val);
		return true;
	}

	/** Removes a value from the set. Returns true if the set contained the specified element. */
	bool remove(int val) {
		if (hash.count(val) == 0) return false;
		int pos = hash[val];
		hash[vec.back()] = pos;
		vec[pos] = vec.back();
		hash.erase(val);
		vec.pop_back();
		return true;
	}

	/** Get a random element from the set. */
	int getRandom() {
		return vec[rand() % vec.size()];
	}
private:
	unordered_map<int, int> hash;
	vector<int> vec;
};
