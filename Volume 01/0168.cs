using System;
using System.Collections.Generic;

class Program {
	public static int Main() {
#if DEBUG
		Console.WriteLine("DEBUG Mode");
#endif
		while (true)
		{
			int n = int.Parse(Console.ReadLine());
			if (n == 0)
			{
				break;
			}
			int[] dp = new int[31];
			dp[0] = 1;
			for (int i = 1; i <= n; i++)
			{
				for (int j = 1; j < 4; j++)
				{
					if (i - j < 0)
					{
						break;
					}
					dp[i] += dp[i - j];
				}
			}
			dp[n] = dp[n]/10 + Convert.ToInt32(dp[n] % 10 != 0);
			Console.WriteLine(dp[n] / 365 + Convert.ToInt32(dp[n] % 365 != 0));
		}
		return 0;
	}
}