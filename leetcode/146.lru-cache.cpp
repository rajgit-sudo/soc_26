#include <bits/stdc++.h>
#include <type_traits>
#include <unordered_map>
using namespace std;
using ll=long long;

struct ListNode {
    int key;
	int val;
	ListNode* next;
	ListNode* prev;

	ListNode(int k, int v) : key(k), val(v), next(nullptr), prev(nullptr) {}
};


class LRUCache {
public:
    int maxCapacity;
    unordered_map<int, ListNode*> cache;
    ListNode* head;
    ListNode* tail;

    LRUCache(int capacity) {
        maxCapacity = capacity;
        head = new ListNode(0, 0);
        tail = new ListNode(0, 0);

        head->next = tail;
        tail->prev = head;
    }

    void removeNode(int key){
        ListNode* node = cache[key];

        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void insertEnd(int key){
        ListNode* node = cache[key];

        node->prev = tail->prev;
        node->next = tail;

        tail->prev->next = node;
        tail->prev = node;
    }

    int get(int key) {
        if(!cache.contains(key))
            return -1;

        int ans = cache[key]->val;
        removeNode(key);
        insertEnd(key);
        return ans;
    }

    void put(int key, int value) {
        if(cache.contains(key)){
            cache[key]->val = value;
            removeNode(key);
            insertEnd(key);
        }else{
            ListNode* newNode = new ListNode(key, value);
            cache[key] = newNode;
            insertEnd(key);

            if(int(cache.size()) > maxCapacity){
                ListNode* lru = head->next;
                removeNode(lru->key);
                cache.erase(lru->key);
                delete lru;
            }
        }
    }
};
