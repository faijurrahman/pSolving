
bool isPrime(int n)
{
	if(n<2)return false;
	for(int i=2; i*i<=n; i++)
		if(n%i==0) return false;
	return true;
}

map<int,int> primeFactorList(int n)
{
	map<int,int> pl;
	for(int i=2; i*i<=n; i++)
		while(n%i==0){pl[i]++; n/=i;}
	if(n>1) pl[n]++;
	return pl;
}

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