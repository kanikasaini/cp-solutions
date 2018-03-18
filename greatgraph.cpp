#include<bits/stdc++.h>
using namespace std;
long long n,m;
vector <long long> G[100010];
vector <long long> black, white;
bool visited[100010];
bool proc[100010];
int color[100010];
bool flag;
void bfs(long long start)
{
	visited[start]=true;
	queue <long long> q;
	q.push(start);
	while(!q.empty())
	{
		long long cur = q.front();
		q.pop();
		for(long long i=0;i<G[cur].size();i++)
		{
			if(!proc[cur])
			{
				if(color[cur]==color[G[cur][i]])
					flag=false;
				if(color[cur]==1)
				{
					color[G[cur][i]]=2;
				}
				else
				if(color[cur]==2)
				{
					color[G[cur][i]]=1;
		//			white.push_back(G[cur][i]);
				}

				if(!visited[G[cur][i]])
				{
					visited[G[cur][i]]=true;
					q.push(G[cur][i]);
				}
			}
		}
		proc[cur]=true;

	}
}
void bipartite()
{
	memset(color, 0, sizeof(color));
	for(long long i=1;i<=n; i++)
	{
		if(!visited[i])
		{
			color[i]=1;
		//	white.push_back(i);
			bfs(i);
		}
	}

}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); 
	cin>>n>>m;
	long long ai,bi,i;
        int c;
        memset(visited, false, sizeof(visited));
	memset(proc, false, sizeof(proc));
        for (i=0; i<m;i++)
        {
                cin>>ai>>bi;
                G[ai].push_back(bi);
                G[bi].push_back(ai);
        }
	flag= true;
	bipartite();
	if(flag==0)
	cout<<-1<<"\n";
	else
	{
		for(i=1;i<=n;i++)
		{
			if(color[i]==1)
			white.push_back(i);
			else
			if(color[i]==2)
			black.push_back(i);
		}
		cout<<white.size()<<"\n";
		for(i=0;i<white.size(); i++)
			cout<< white[i]<<" ";
		cout<<"\n"<<black.size()<<"\n";
		for(i=0;i<black.size();i++)
			cout<< black[i]<< " ";
	}
	return 0;
}
