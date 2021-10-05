#include <bits/stdc++.h>

using namespace std;

string decodeString(string s) {
        int n=s.size();
        stack<char> st;
        int i=0;
        string t,r;
        int no;
        for(i=0;i<n;i++){
            if(s[i]==']') {
                t.clear();
                while(!st.empty() && st.top()>='a' && st.top()<='z'){
                    t+=st.top();
                    st.pop();
                }
                reverse(t.begin(),t.end());
                if(!st.empty())
                    st.pop();
                r.clear();
                while(!st.empty() && st.top()>='0' && st.top()<='9'){
                    r+=st.top();
                    st.pop();
                }
                reverse(r.begin(),r.end());
                no=stoi(r);
                string str="";
                while(no--){
                    str.append(t);
                }
                for( char x : str){
                    st.push(x);
                }
            } else {
                st.push(s[i]);
            }
        }
        string ans="";
        while(!st.empty()) {
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    
int main()
{
  string cString, dString;
  cin>>cString;
  dString = decodeString(cString);
  cout<<dString;
}
    
