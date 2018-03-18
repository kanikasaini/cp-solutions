#include<bits/stdc++.h>
using namespace std;
int main()
{
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
	int t;
	long long n,k;
	cin>>t;
	vector<long long> a;
	long long ts, fs, es;
	long long temp, in, j, i;
	while(t--)
	{
		a.clear();
		ts=es=fs=0;
		cin>>n>>k;
		for(i=0; i<n; i++)
		{
			cin>>temp;
			ts+=temp;
			a.push_back(temp);
		}
		temp=0;
		for(i=n-1; i>=0; i--)
		{
			temp+=a[i];
			if(temp>fs)
				fs=temp;
		}
		temp=0;
		for(i=0; i<n; i++)
		{
			temp+=a[i];
			if(temp>es)
				es=temp;
		}
		if(ts<0)
		{
			if((k-2)*ts+es>0)
				cout<<es+fs+(k-2)*ts;
			else(if)
		}
		else
		{
			ts=(k-2)*ts;
			ts+=es+fs;
		}
		cout<<ts<<endl;
	}
	return 0;
}
