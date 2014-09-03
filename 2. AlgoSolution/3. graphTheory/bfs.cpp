
//Basic Example
bfs(int start, int required)
{
    queue queu;
    bool visited[n+1];

    for(int i = 0; i <= n; i++) visited[i] = false;

    queu.push(start);
    visited[start] = true;
    while(!queu.empty())
    {
        int curNode = queu.front();queu.pop_front();
        if(curNode == required) break;
        
        for(int i = 0; i <= n; i++)
			if (isConnected(curNode, i) && !visited[i]) 
			{
				queu.push(i);
				visited[i] = true;
			}
    }
} 

