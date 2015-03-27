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
	  string searchString = cin.next();
	  int n = cin.nextInt();
    string[] rings = new string[n];
	  int ans = 0;
    for (int i = 0; i < n; i++)
	  {
	    rings[i] = cin.next();
	    rings[i] += rings[i];
	    if (rings[i].IndexOf(searchString) != -1)
	    {
	      ++ans;
	    }
	  }
    Console.WriteLine(ans);
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