class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
    if(s1.length()>s2.length())
    {
        return false;
    }

    int windowsize=s1.length();
    vector<int> freq1 (26,0);
    vector<int> freq2 (26,0);

    for(int i=0;i<s1.length();i++)
    {
        freq1[s1[i]-'a']++;
    }

    //first window

    for(int i=0;i<windowsize;i++)
    {
        freq2[s2[i]-'a']++;
    }
    
    
    if(freq1==freq2)
    {
        return true;
     }
    //remaining windows

    int left=0;
    for(int right=windowsize;right<s2.length();right++)
    {
        freq2[s2[right]-'a']++;

        freq2[s2[left]-'a']--;

        left++;

        if(freq1==freq2)
        {
            return true;
        }
    }
  return false;
    }
};