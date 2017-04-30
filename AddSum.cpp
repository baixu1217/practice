#include<vector>
#include <utility>
#include<iostream>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        size_t size = nums.size();
        vector<int> v;
        for(int i = 0; i < size-1;++i)
        {
            if(target == nums[i]+nums[i+1])
            {
                v.push_back(i);
                v.push_back(i+1);
                return v;
            }
        }
    }
};

void TestAddSum()
{
	Solution s;
	vector<int> v;
	vector<int> v1;

	v.push_back(2);
	v.push_back(7);
	v.push_back(11);
	v.push_back(15);

	int target = 9;
	v1 = s.twoSum(v,target);
	int size = v1.size();
	int i = 0;
	while(size--)
	{
		cout<<v1[i]<<" ";
		i++;
	}

}

int main()
{
	TestAddSum();
	return 0;
}
