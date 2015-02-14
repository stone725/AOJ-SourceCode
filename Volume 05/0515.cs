using System;
using System.Collections.Generic;

class Program {
	public static int Main() {
#if DEBUG
		Console.WriteLine("DEBUG Mode");
#endif
		while (true)
		{
			int h, w;
			string[] size = Console.ReadLine().Split(' ');
			h = int.Parse(size[0]);
			w = int.Parse(size[1]);
			if (h == 0 || w == 0)
			{
				break;
			}
			int[,] dp = new int[h + 1,w + 1];
			for (int i = 0; i < h + 1; i++)
			{
				for (int j = 0; j < w + 1; j++)
				{
					dp[i, j] = -1;
				}
			}
			for (int i = 0; i <= h; i++)
			{
				dp[i, 0] = 0;
			}
			for (int i = 0; i <= w; i++)
			{
				dp[0, i] = 0;
			}
			dp[1, 1] = 1;
			int n = int.Parse(Console.ReadLine());
			for (int i = 0; i < n; i++)
			{
				int x, y;
				string[] str = Console.ReadLine().Split(' ');
				x = int.Parse(str[0]);
				y = int.Parse(str[1]);
				dp[x, y] = 0;
			}
			for (int i = 1; i <= h; i++)
			{
				for (int j = 0; j <= w; j++)
				{
					if (dp[i, j] == -1)
					{
						dp[i, j] = dp[i - 1, j] + dp[i, j - 1];
					}
				}
			}
			Console.WriteLine(dp[h, w]);
		}
		return 0;
	}
}