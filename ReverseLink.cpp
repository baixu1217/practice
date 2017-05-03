#include<iostream>
using namespace std;
#include<vector>
#include<stack>

  struct ListNode {
        int val;
        struct ListNode *next;
        ListNode(int x) :
              val(x), next(NULL) {
        }
  };

class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        stack<int> nodes;
        ListNode* cur = head;
        vector<int> v;
		int value;
        int i = 0;
        while(cur)
            {
				nodes.push(cur->val);
				cur = cur->next;
        }
        while(!nodes.empty())
            {
				value = nodes.top();
				v.push_back(value);
				nodes.pop();
        }
        return v;
    }
};