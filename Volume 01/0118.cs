using System;
using System.Collections.Generic;
using System.ComponentModel.Design;

class Program
{
	private static int h, w;
	private static char[][] m = new char[100][];
	private static int[] dx = new[] {0, 1, 0, -1, 1, 1, -1, -1};
	private static int[] dy = new[] {1, 0, -1, 0, 1, -1, 1, -1};
	public static int Main()
	{
		Scanner cin = new Scanner();
		while (true)
		{
			h = cin.nextInt();
			w = cin.nextInt();
			if (h == 0 || w == 0)
			{
				break;
			}
			int ans = 0;
			for (int i = 0; i < h; i++)
			{
				m[i] = cin.next().ToCharArray();
			}
			for (int i = 0; i < h; i++)
			{
				for (int j = 0; j < w; j++)
				{
					if (m[i][j] != '.')
					{
						dfs(i, j, m[i][j]);
						ans++;
					}
				}
			}
			Console.WriteLine(ans);
		}
		return 0;
	}

	public static void dfs(int x, int y, char nowchar)
	{
		m[x][y] = '.';
		for (int i = 0; i < 4; i++)
		{
			if (x + dx[i] < 0 || y + dy[i] < 0 || x + dx[i] == h || y + dy[i] == w || nowchar != m[x + dx[i]][y + dy[i]])
			{
				continue;
			}
			dfs(x + dx[i], y + dy[i], nowchar);
		}
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