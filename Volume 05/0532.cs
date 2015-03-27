using System;
using System.Collections.Generic;
using System.Data.SqlTypes;
using System.IO.Pipes;
using System.Linq;

class Program
{ 
	public static int Main()
	{
		//Scanner cin = new Scanner();
		string line;
		while (!string.IsNullOrEmpty(line = System.Console.ReadLine())) {
			string[] l = line.Split(' ');
			TimeSpan s = new TimeSpan(int.Parse(l[0]), int.Parse(l[1]), int.Parse(l[2]));
			TimeSpan e = new TimeSpan(int.Parse(l[3]), int.Parse(l[4]), int.Parse(l[5]));
			e -= s;
			Console.WriteLine("{0} {1} {2}", e.Hours, e.Minutes, e.Seconds);
		}
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