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
	  int n = cin.nextInt();
    int[] score = new int[n];
	  for (int i = 0; i < n * (n - 1) / 2; i++)
	  {
	    int a = cin.nextInt() - 1, b = cin.nextInt() - 1, c = cin.nextInt(), d = cin.nextInt();
	    if (c > d)
	    {
	      score[a] += 3;
	    }
      else if (c < d)
      {
        score[b] += 3;
      }
      else
      {
        ++score[a];
        ++score[b];
      }
	  }
    for (int i = 0; i < n; i++)
    {
      int res = 1;
      for (int j = 0; j < n; j++)
      {
        if (score[i] < score[j])
        {
          ++res;
        }
      }
      Console.WriteLine(res);
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