int popCount(unsigned int num)
{
	int cnt=0;
	loop(i,32) if(num & 1<<i) cnt++;
	return cnt;
}

bool isOne(int num, int pos)
{
	return num & 1<<pos;
}