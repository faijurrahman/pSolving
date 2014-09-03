int gcd(int m, int n )
{
	int rem;
	while(n!=0)
	{
		rem = m%n;
		m = n;
		n = rem;
	}
	return m;
}

long lcm(int m, int n )
{
	return((long)(m*n)/gcd(m,n) );
}

class gcdLcm
{
	long long gcd(long long m, long n )
	{
	/*
		long rem;
		while( n != 0 )
		{
			rem = m % n;
			m = n;
			n = rem;
		}
	*/
		while(n) (m%=n)^=n^=m^=n;
		return m;
	}

	long long lcm(long long m, long n )
	{
		return((long long)(m*n)/gcd(m,n) );
	}

public:
	long multiGCD(vector<int> data)
	{
		long gcdVal = data[0];
		for(int i=1; i<data.size(); i++) gcdVal = gcd(gcdVal, data[i]);
		return gcdVal;
	}

	long long multiLCM(vector<int> data)
	{
		long long lcmVal = data[0];
		for(int i=1; i<data.size(); i++) lcmVal = lcm(lcmVal, data[i]);
		return lcmVal;
	}
};

class gcdLcmSTL
{
	template<class Type>
	 long long gcd(long long m, Type n )
	{
		Type rem;
		while( n != 0 )
		{
			rem = m % n;
			m = n;
			n = rem;
		}
		return m;
	}

	template<class Type>
	long long lcm( long long m, Type n )
	{
		return((long long)(m*n)/gcd(m,n) );
	}

public:
	template<class Type>
	Type multiGCD(vector<Type> data)
	{
		Type gcdVal = data[0];
		for(int i=1; i<data.size(); i++) gcdVal = gcd(gcdVal, data[i]);
		return gcdVal;
	}

	template<class Type>
	long long multiLCM(vector<Type> data)
	{
		long long lcmVal = data[0];
		for(int i=1; i<data.size(); i++) lcmVal = lcm(lcmVal, data[i]);
		return lcmVal;
	}
};
