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
	  string str = cin.next();
	  char[] s = str.ToCharArray();
	  for (int i = 0; i < s.Length; i++)
	  {
	    s[i] -= 'A';
	    int a = s[i];
	    a += 23;
	    a %= 26;
	    s[i] = Convert.ToChar(a);
	    s[i] += 'A';
	  }
    Console.WriteLine(s);
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