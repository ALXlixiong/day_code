class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<int,int> m;
        int left = 0;
        int ret = 0;
        for(int i = 0;i<s.size();++i)
        {
            //"tmmzuxt"
            if(m.count(s[i]) == 0 || m[s[i]]<left)
            {
                m[s[i]] = i;
                ret = max(ret,i-left+1); 
            }
            else
            {
                left = m[s[i]]+1;
                m[s[i]] = i;
            }
        }
        return ret;
    }
};
