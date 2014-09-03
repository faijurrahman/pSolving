#define MOD (int)(1e9+7)
#define CN (50+1)
int ncr[CN][CN];
ZERO(ncr); loop(i,CN) ncr[i][0]=1;
loop(i,CN-1) loop(j,i+1) ncr[i+1][j+1] = (ncr[i][j]+ncr[i][j+1])%MOD;


#define MOD (int)(1e9+7)
#define CN (50+1)
int ncr[CN][CN];
void cal_ncr(void)
{
	for(int i=0;i<CN;i++) ncr[i][0]=1;
	for(int i=1;i<CN;i++) for(int j=1;j<=i;j++) 
		ncr[i][j] = (ncr[i-1][j-1] + ncr[i-1][j]) % MOD;
}