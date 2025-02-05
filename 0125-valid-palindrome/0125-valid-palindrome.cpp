class Solution {
public:
    bool valid(char ch)
    {
        if((ch>='a' && ch<='z') || (ch>='A' && ch<='Z') || (ch>='0' && ch<='9'))
        {
            return 1;
        }
        return 0;
    }
    char lowerCase(char ch)
    {
        if((ch>='a' && ch<='z')) return ch;
        else
        {
            char temp=ch-'A'+'a';
            return temp;
        }
    }
    bool checkPalindrom(string s)
    {
        int i=0;
        int j=s.length()-1;
        while(i<=j)
        {
            if(s[i]!=s[j]) return false;
            else
            {
                i++;
                j--;
            }
        }
        return true;
    }
    bool isPalindrome(string s) {
        string temp="";
        for(int i=0;i<s.length();i++)
        {
            if(valid(s[i]))
            {
                temp.push_back(s[i]);
            }
        }
        for(int i=0;i<temp.length();i++)
        {
            temp[i]=lowerCase(temp[i]);
        }
        return checkPalindrom(temp);
    }
};