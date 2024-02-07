string findLCS(int n, int m,string &s1, string &s2){
	vector<vector<int>> dp(n+1, vector<int>(m+1,0));
	for(int ind1=1; ind1<=n; ind1++) {
		for(int ind2=1; ind2<=m; ind2++) {
			if(s1[ind1-1] == s2[ind2-1])
				dp[ind1][ind2] = 1+dp[ind1-1][ind2-1];
			else
				dp[ind1][ind2] = max(dp[ind1-1][ind2],dp[ind1][ind2-1]);
		}
	}
	int maxLen = dp[n][m];

	string ans(maxLen,'$');
	int index = maxLen-1;
	int i=n; int j=m;

	while(i>0 && j>0) {
		if(s1[i-1] == s2[j-1])
		{
			ans[index] = s1[i-1];
			index--;
			i--; j--;
		}
		else if(dp[i-1][j] > dp[i][j-1]) {
			i--;
		}
		else {
			j--;
		}
	}
	return ans;
}