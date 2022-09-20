# Longest Substring Without Repeating Characters
class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        counter=0
        i = 0
        maxVal=0
        sub=""
        while ( i < len(s) ):
            if(s[i] not in sub):
                sub+=s[i]
                counter+=1
            else:
                i -= len(sub)
                counter=0
                sub=""
                
            if(counter>maxVal):
                maxVal = counter
                
            i+=1
            
        return maxVal
                
                
        