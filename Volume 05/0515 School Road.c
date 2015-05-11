#include<stdio.h>
#include<string.h>

int main(){
	int a, b, n, x, y, i, j;
  int dp[17][17];
  while( scanf("%d %d", &a, &b) != EOF && a && b ){	
  	memset( dp, -1, sizeof(dp) );	
  	scanf( "%d", &n );
  	for( i = 0; i <= a; i++ ){
			dp[i][0] = 0;
		}
		for( i = 0; i <= b; i++ ){
			dp[0][i] = 0;
		}
		dp[1][1] = 1;
		for( i = 0; i < n; i++ ){
      scanf( "%d %d", &x, &y );
      dp[x][y] = 0;
		}
		for( i = 1; i <= a; i++ ){ 
			for( j = 1; j <= b; j++ ){
        if( dp[i][j] != -1 ){
					continue;
				}
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			}
		}
		printf( "%d\n", dp[a][b] );
	}
	return 0;
}