vector<int> getDivisors(int n)
{
    vector<int> div;
    for(int i=1; i*i<=n; i++) if(n%i==0) 
	{   
		div.push_back(i);
		if(n/i!=i) div.push_back(n/i);
    }
    sort(div.begin(), div.end());
    return div;
}