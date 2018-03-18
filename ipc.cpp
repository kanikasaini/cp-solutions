#include<bits/stdc++.h>
using namespace std;
struct trainer {
   int dj;
   int t;
   int s;
};
int compare(const void *s1, const void *s2)
{
          struct trainer *e1 = (struct trainer *)s1;
	  struct trainer *e2 = (struct trainer *)s2;
	  return e2->s - e1->s;
}
int main()
{
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
	int t,n,d;
	cin>>t; 
	while(t--)
	{	
		cin>>n>>d;
		trainer ar[n];
		bool days[d+1];
		memset(days, false, sizeof(days));
		int i=0;
		long long sad;
		sad=0;
		while(i<n)
		{
			cin>>ar[i].dj>>ar[i].t>>ar[i].s;
			sad+=ar[i].s*ar[i].t;
			i++;
		}
		qsort(ar, n, sizeof(struct trainer), compare);
		for(int j=0;j<n;j++)
		{
			int lec=ar[j].t;
			int in=ar[j].dj;
			while(in<=d && lec>0)
			{
				if(days[in]==false)
				{
					lec--;
					days[in]=true;
					sad-=ar[j].s;
				}
				in++;
			}
		}
		cout<<sad;
		cout<<"\n";
	}
	return 0;
}
