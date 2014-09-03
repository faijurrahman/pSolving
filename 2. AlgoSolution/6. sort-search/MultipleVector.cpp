//Sorting multiple STL togather based on some rule
	template <class Type> void sortMulti(vector<Type>& X, vector<Type>& Y)
	{
		int n = X.size();

		for(int i = 0; i < n; i++)
		{
			int t = i;
			for(int j = i; j < n; j++)
				if(X[t] > X[j]) 
					t = j;

			if(t != i)
			{
				std::swap(X[i],	X[t]);
				std::swap(Y[i],	Y[t]);				
			}
		}
	}

    template <class Type> void sortMulti(vector<Type>& X, vector<Type>& Y)
	{
		vector<Type> B;
		int n = X.size();

		for(int i = 0; i < n; i++)
		{
			B.push_back(X[i]);
			//B.push_back(X[i] + Y[i]);
			//B.push_back(abs(X[i] - Y[i]));
		}

		for(int i = 0; i < n; i++)
		{
			int t = i;
			for(int j = i; j < n; j++)
			{
				if(B[t] > B[j]) 
				{
					t = j;
				}
			}

			if(t != i)
			{
				std::swap(B[i], B[t]);
				std::swap(X[i],	X[t]);
				std::swap(Y[i],	Y[t]);
				
			}
		}
	}