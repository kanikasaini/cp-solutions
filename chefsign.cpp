#include<bits/stdc++.h>
using namespace std;
void func(string s)
{
	long long maxcnt,cnt;
	maxcnt=0;
	cnt=0;
	long long i=0;
	while(i<s.length())
	{
		if(s[i]=='<')
		{
			while(i<s.length() && s[i]!='>')
			{
				if(s[i]=='<')
					cnt++;
				i++;
			}
			if(cnt>maxcnt)
				maxcnt=cnt;
			cnt=0;
		}
		else
		if(s[i]=='>')
		{
			while(i<s.length() && s[i]!='<')
			{
				if(s[i]=='>')
					cnt++;
				i++;
			}
			if(cnt>maxcnt)
				maxcnt=cnt;
			cnt=0;
		}
		else
			i++;
	}
	cout<<maxcnt+1;
	cout<<"\n";
}
int main()
{
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
	long long t;
	cin>>t;
	string s;
	while(t--)
	{
		cin>>s;
		func(s);
	}
        return 0;
}

