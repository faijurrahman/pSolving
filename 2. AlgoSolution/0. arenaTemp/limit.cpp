	bool isInLimit(int val, int lowLim, int highLim)
	{
		if(lowLim<=x && x<highLim)
		{
			return true;
		}
		return false;
	}
	
	int xLim, yLim;
	bool isInLimit(int x, int y)
	bool isInLimit(int x, int y, int xLim, int yLim)
	{
		if(0<=x && x<xLim)
		{
			if(0<=y && y<yLim)
			{
				return true;
			}
		}
		return false;
	}
	
	int xLim, yLim, zLim;
	bool isInLimit(int x, int y, int z)
	bool isInLimit(int x, int y, int z, int xLim, int yLim, int zLim)
	{
		if(0<=x && x<xLim)
		{
			if(0<=y && y<yLim)
			{
				if(0<=z && z<zLim)
				{
					return true;
				}
			}
		}
		return false;
	}