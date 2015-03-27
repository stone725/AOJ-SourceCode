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
	  int[] w = new int[10];
    int[] k = new int[10];
	  for (int i = 0; i < 10; i++)
	  {
	    w[i] = cin.nextInt();
	  }
	  for (int i = 0; i < 10; i++)
	  {
	    k[i] = cin.nextInt();
	  }
    Array.Sort(w);
    Array.Reverse(w);
    Array.Sort(k);
    Array.Reverse(k);
    int[] W = new int[3];
    int[] K = new int[3];
    Array.Copy(w, W, 3);
    Array.Copy(k, K, 3);
    Console.WriteLine("{0} {1}", W.Sum(x => x), K.Sum(x => x));
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