using System;
using System.Collections.Generic;
using System.Data.SqlTypes;
using System.IO.Pipes;
using System.Linq;

class Program
{ 
	public static int Main()
	{
		Scanner cin = new Scanner();
		int[] a = new int[4];
		int[] b = new int[4];
		for (int i = 0; i < 4; i++)
		{
			a[i] = cin.nextInt();
		}
		for (int i = 0; i < 4; i++)
		{
			b[i] = cin.nextInt();
		}
		Console.WriteLine(Math.Max(a.Sum(x => x), b.Sum(x => x)));
		return 0;
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