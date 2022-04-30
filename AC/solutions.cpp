class Solution {
public:

	//Problem: 41. First Missing Positive (https://leetcode.com/problems/first-missing-positive/)
	//Level: Hard
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int res = 1;
        int n = nums.size();
        for(int i = 0; i < n; ++i)
        {
            if(res < nums[i])
                return res;
            if(res == nums[i])
                ++res;
        }
        return res;
    }
	
	//Problem: 1402. Reducing Dishes (https://leetcode.com/problems/reducing-dishes/)
	//Level: Hard
	int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        if(satisfaction.back() < 0)
            return 0;
        int n = satisfaction.size();
        vector<int> coefs(n);
        int i, j;
        for(i = 0; i < n; ++i)
        {
            for(j = 0; j <= i; ++j)
                coefs[j] += satisfaction[i] * (i - j + 1);
        }
        int max = coefs[0];
        for(i = 1; i < n; ++i)
        {
            if(max < coefs[i])
                max = coefs[i];
        }
        return max;
    }
	
	//Problem: 2. Add Two Numbers (https://leetcode.com/problems/add-two-numbers/)
	//Level: Medium
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        bool isRemaining = false;
        ListNode *p = nullptr;
        ListNode *q = nullptr;
        int val;
        while(l1 != nullptr || l2 != nullptr)
        {
            val = isRemaining;
            if(l1 != nullptr)
            {
                val += l1->val;
                l1 = l1->next;
            }
            if(l2 != nullptr)
            {
                val += l2->val;
                l2 = l2->next;
            }
            if(val >= 10)
            {
                val -= 10;
                isRemaining = true;
            }
            else
                isRemaining = false;
            if(p == nullptr)
            {
                p = new ListNode(val);
                q = p;
            }
            else
            {
                q->next = new ListNode(val);
                q = q->next;
            }
        }
        if(isRemaining)
            q->next = new ListNode(1);
        return p;
    }
	
	//Problem: 3. Longest Substring Without Repeating Characters (https://leetcode.com/problems/longest-substring-without-repeating-characters/)
	//Level: Medium
	int lengthOfLongestSubstring(string s) {
        int size = s.size();
        if(size == 0)
            return 0;
        vector<int> len(size);
        map<char, int> mymap;
        map<char, int>::iterator it;
        int index = -1;
        for(int i = 0; i < size; ++i)
            len[i] = 1;
        int i = 0;
        int j = 0;
        for(i = 0; i < size; ++i)
        {
            it = mymap.find(s[i]);
            if(it != mymap.end())
            {
                if(it->second > index)
                    index = it->second;
            }
            mymap[s[i]] = i;
            for(j = index + 1; j < i; ++j)
                ++len[j];
        }
        j = 0;
        for(i = 1; i < size; ++i)
        {
            if(len[i] > len[j])
                j = i;
        }
        return len[j];
    }
	
	//Problem: 6. Zigzag Conversion (https://leetcode.com/problems/zigzag-conversion/)
	//Level: Medium
	string convert(string s, int numRows) {
        if(numRows == 1 || numRows == s.size())
            return s;
        string res = "";
        vector<vector<char>> rows(numRows);
        bool isAscending = true;
        int rowIdx = 0;
        for(auto const &c: s)
        {
            rows[rowIdx].push_back(c);
            if(isAscending)
            {
                if(rowIdx < numRows - 1)
                    ++rowIdx;
                else
                {
                    --rowIdx;
                    isAscending = false;
                }
            }
            else
            {
                if(rowIdx > 0)
                    --rowIdx;
                else
                {
                    ++rowIdx;
                    isAscending = true;
                }
            }
        }
        for(int i = 0; i < numRows; ++i)
        {
            for(auto const &c: rows[i])
                res.push_back(c);
        }
        return res;
    }
	
	//Problem: 7. Reverse Integer (https://leetcode.com/problems/reverse-integer/)
	//Level: Medium
	int reverse(int x) {
        bool isNegative = (x < 0);
        int res = 0;
        int digit;
        while(x != 0)
        {
            digit = abs(x) % 10;
            if((INT_MAX - digit) / 10 < res)
                return 0;
            res = res * 10 + digit;
            x /= 10;
        }
        if(isNegative)
            res = -res;
        return res;
    }
	
	//Problem: 8. String to Integer (atoi) (https://leetcode.com/problems/string-to-integer-atoi/)
	//Level: Medium
    int myAtoi(string str) {
        int res = 0;
        int len = str.size();
        bool isBegin = false;
        bool isNegative = false;
        bool checkSign = false;
        for(int i = 0; i < len; ++i)
        {
            if(str[i] != ' ')
            {
                if(str[i] >= '0' && str[i] <= '9')
                {
                    if((INT_MAX - (str[i] - '0')) / 10 < res)
                        return (isNegative)? INT_MIN : INT_MAX;
                    res = res * 10 + (str[i] - '0');
                    if(!isBegin)
                        isBegin = true;
                    if(!checkSign)
                        checkSign = true;
                }
                else
                {
                    if(!isBegin)
                    {
                        if((str[i] == '-' || str[i] == '+') && !checkSign)
                        {
                            checkSign = true;
                            isBegin = true;
                            isNegative = (str[i] == '-');
                        }
                        else
                            return res;
                    }
                    else
                        break;
                }
            }
            else
            {
                if(isBegin)
                    break;
            }
        }
        if(isNegative)
            res = -res;
        return res;
    }
};