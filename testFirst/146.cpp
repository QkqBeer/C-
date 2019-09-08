#include <iostream>
#include <unordered_map>
#include <list>
#include <future>
using namespace std;

//struct Node {
//	int key;
//	int val;
//	Node* pre;
//	Node* next;
//};
class LRUCache {
public:
	LRUCache(int capacity) {
		this->cap = capacity;
	}

	int get(int key) {
		auto it = hash_map.find(key);
		if (it == hash_map.end())
		{
			return -1;
		}
		else
		{
			pair<int, int> tmp = *hash_map[key];
			cache.erase(hash_map[key]);
			cache.push_front(tmp);
			hash_map[key] = cache.begin();
			return tmp.second;
		}
	}

	void put(int key, int value) {
		auto it = hash_map.find(key);
		if (it != hash_map.end())
		{
			cache.erase(hash_map[key]);
			cache.push_front(make_pair(key, value));
			hash_map[key] = cache.begin();
		}
		else
		{
			if (cache.size() == cap)
			{
				auto it = cache.back();
				auto k = it.first;
				hash_map.erase(k);
				cache.pop_back();
			}
			cache.push_front(make_pair(key, value));
			hash_map[key] = cache.begin();
		}
	}
private:
	int cap;
	unordered_map<int, list<pair<int, int>>::iterator> hash_map;
	list<pair<int, int>> cache;
};

//int main()
//{
//	/*short a[100];
//	cout << sizeof(a) << endl;*/
//
//	/*char string[10];
//	char* str1 = "0123456789";
//	strcpy(string, str1);*/
//
//	/*int x = 10, y = 3;
//	printf("%d\n", y = x / y);*/
//
//	int i = 0, sum = 1;
//	do {
//		sum += i++;
//	} while (i < 5);
//	cout << sum << endl;
//
//	char c = 'A' + 10;
//	cout << c;
//	return 0;
//}