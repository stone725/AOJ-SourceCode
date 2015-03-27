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
	  string input;
	  while (!string.IsNullOrEmpty(input = Console.ReadLine()))
	  {
	    int cnt = 0, s = 0;
	    while (input.IndexOf("JOI", s) != -1)
	    {
	      ++cnt;
	      s = input.IndexOf("JOI", s) + 1;
	    }
      Console.WriteLine(cnt);
	    cnt = s = 0;
      while (input.IndexOf("IOI", s) != -1) {
        ++cnt;
        s = input.IndexOf("IOI", s) + 1;
      }
      Console.WriteLine(cnt);
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