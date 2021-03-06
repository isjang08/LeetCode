// Runtime: 24 ms (60%)
// Memory Usage: 23.8 MB (93%)
#ifndef LEETCODE
#define LEETCODE

#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <map>
#include <math.h>
using namespace std;


class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans;
        int len = nums.size();
        ans.resize(len);
        
        //except for zero
        vector<int> zero_ans;
        for (int i = 0; i < len; i++)
        {
            if(nums[i] == 0)
                zero_ans.push_back(i);
        }

        // 1. 1개 일때 
        if (zero_ans.size() == 1)
        {
            //Get total Multiplication
            int totalMult = 1;
            for (int i = 0; i < len; i++)
            {
                if (i == zero_ans[0]) {                    
                    continue;
                }                    
                totalMult *= nums[i];
            }
            fill(ans.begin(), ans.end(), 0);
            ans[zero_ans[0]] = totalMult;
            return ans;
        }

        //2. 2개 이상일떄
        if (zero_ans.size() > 1)
        {
            fill(ans.begin(), ans.end(), 0);
            return ans;
        }

        // Get total multiplication 
        int totalMult = 1;
        for (int i = 0; i < len; i++)
        {
            totalMult *= nums[i];
        }
        
        for (int i = 0; i < len; i++)
        {
            ans[i] = totalMult / nums[i];
        }
        
        return ans;
    }
};


int main() {
    Solution sol;
    vector<int> nums { 1, 2, 3, 4 };
    sol.productExceptSelf(nums);
    return 0; 
}

#endif //LEETCODE

//python 
// Runtime: 252 ms
// Memory Usage: 22.5 MB
from typing import List 
class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        front = []
        reverse = []

        tmp = 1
        length = len(nums)
        for x in range(0, length):
            front.append(tmp)
            tmp *= nums[x]
        
        tmp = 1
        for x in reversed(range(0, length)):
            reverse.append(tmp)
            tmp *= nums[x]

        ans = []
        for x in range(0, length):
            ans.append(front[x] * reverse[length - x - 1])

        return ans;
        
sol = Solution()
nums = [1,2,3,4]
ans = sol.productExceptSelf(nums)
print(ans)
