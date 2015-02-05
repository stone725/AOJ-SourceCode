using System;
using System.Text;
using System.Collections;
using System.Collections.Generic;

using System.Linq;
using System.Text.RegularExpressions;
using System.Diagnostics;
using System.Threading; 


class Program
{
	public const int Inf = 1 << 29;
	public static int[,] dp = new int[100,100];
	public static int[,] arrayList = new int[100,100];
	public static int cnt = 0;
	static void Main()
	{
		string line;
		for (int i = 0; i < 100; ++i) {
			for (int j = 0; j < 100; j++) {
				dp[i, j] = -1;
				arrayList[i, j] = -1;
			}
		}
		while (!string.IsNullOrEmpty(line = Console.ReadLine())) {
			string[] s = line.Split(',');
			
			for (int i = 0; i < s.Length; i++)
			{
				arrayList[cnt, i] = int.Parse(s[i]);
			}
			cnt++;
		}
		
		Console.WriteLine(solve(0, 0));
	}

	static int solve(int a, int b)
	{

		if (cnt == a)
		{
			return 0;
		}
		if (b < 0 || arrayList[a,b] == -1)
		{
			return -Inf;
		}
		if (dp[a,b] >= 0)
		{
			return dp[a,b];
		}
		var res = cnt / 2 > a ? Math.Max(solve(a + 1, b) + arrayList[a,b], solve(a + 1, b + 1) + arrayList[a,b]) : Math.Max(solve(a + 1, b) + arrayList[a,b], solve(a + 1, b - 1) + arrayList[a,b]);
		return dp[a,b] = res;
	}
}
