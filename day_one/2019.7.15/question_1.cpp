
class Solution {
public:
    // 使用中心扩展算法
    string longestPalindrome(string s) { 
        if(s.size()<2)
            return s;
        int maxlength = 0;
        int start = 0;
        for(int i = 0;i<s.size();++i)
        {
            //处理奇数长度(aba)
            int len1 = _longestPalindrome(s,i,i);
            //处理偶数长度
            int tmp = i+1;
            int len2 = _longestPalindrome(s,i,tmp);
            if(maxlength<max(len1,len2))
            {
                maxlength = max(len1,len2);
                start = i;
            }
        }
        return s.substr(start-(maxlength-1)/2,maxlength);
    }
    int _longestPalindrome(string s,int &left,int &right)
    {
        int begin = left;
        int end = right;
        while(begin>=0 && end<s.size() && s[begin] == s[end])
        {
            --begin;
            ++end;
        }
        return end-begin-1;   //aba,left=-1,right=3;
    }
};
 
