int src=0, dest=8, V=9;
bool bfs(void)
{
	vector<bool> seen; seen.resize(V,false);
	
	queue<int> q;
	q.push(src); seen[src]=true;
	while(!q.empty())
	{
		int u=q.front(); q.pop();
		loop(v,V) if(isValid(u,v) && !seen[v])
		{
			q.push(v); seen[v]=true;
			if(v==dest) return true;
		}
	}
	return false;
} 

bool dfs(void)
{   
	vector<bool> seen; seen.resize(V,false);

	stack<int> s; 
	s.push(src); seen[src]=true;
	while(!s.empty())
	{
		int u=s.top(); s.pop();            
		loop(v,V) if(isValid(u,v) && !seen[v])
		{
			s.push(v); seen[v]=true;
			if(u==dest) return true; 
		}
	}	
	return false;
} 

