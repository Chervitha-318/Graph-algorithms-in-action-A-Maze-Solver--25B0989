class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    unordered_set<char> seen;
    int maxlen=0;
    int left=0;
    for(int i=0;i<s.size();i++){
        while(seen.count(s[i])){
            seen.erase(s[left]);
            left++;
        }
        seen.insert(s[i]);
        maxlen=max(maxlen,i-left+1);
    }
    return maxlen;    
    }
};
