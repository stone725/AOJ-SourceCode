using System;
using System.Collections.Generic;
using System.ComponentModel.Design;

class Program
{
	private static int n, m;
	public static int Main()
	{
		Scanner cin = new Scanner();
		while (true)
		{
			n = cin.nextInt();
			m = cin.nextInt();
			if (n == 0 && m == 0)
			{
				break;
			}
			Console.WriteLine(dfs(0, 0, 0));
		}
		return 0;
	}

	public static int dfs(int now, int cnt, int many)
	{
		if (now == 10)
		{
			return many == m && cnt == n ? 1 : 0;
		}
		if (many > m || cnt > n)
		{
			return 0;
		}
		return dfs(now + 1, cnt + 1,many + now) + dfs(now + 1, cnt, many);
	}
}

class Scanner {
	string[] s;
	int i;

	char[] cs = new char[] { ' ' };

	public Scanner() {
		s = new string[0];
		i = 0;
	}

	public string next() {
		if (i < s.Length) return s[i++];
		do {
			s = Console.ReadLine().Split(cs, StringSplitOptions.RemoveEmptyEntries);
		} while ((s.Length == 1 && s[0] == "") || s.Length == 0);
		i = 0;
		return s[i++];
	}

	public int nextInt() {
		return int.Parse(next());
	}

	public long nextLong() {
		return long.Parse(next());
	}

	public double nextDouble() {
		return double.Parse(next());
	}

}