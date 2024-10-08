class Solution {
public:
    string addBinary(string a, string b) {
        string ans="";
        int carry = 0;
        int alen = a.length()-1;
        int blen = b.length()-1;
        int i = 0;

        while(i<=alen || i<=blen || carry!=0 ) {
            int x = 0;
            if(i<=alen && a[alen-i]=='1') x = 1;
            int y = 0;
            if(i<=blen && b[blen-i]=='1') y = 1;

            ans = char((x+y+carry)%2 + '0') + ans;
            carry = (x+y+carry)/2;
            i++;
        }
        return ans;
    }
};