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
    int[] cards = new int[2 * n];
	  for (int i = 0; i < 2 * n; i++)
	  {
	    cards[i] = i + 1;
	  }
	  int m = cin.nextInt();
	  while (m-- != 0)
	  {
	    int q = cin.nextInt();
	    if (q == 0)
	    {
	      int[] oneInts = new int[n];
	      int[] twoInts = new int[n];
	      Array.Copy(cards, 0, oneInts, 0, n);
	      Array.Copy(cards, n, twoInts, 0, n);
	      for (int i = 0; i < n; i++)
	      {
	        cards[2 * i] = oneInts[i];
	        cards[2 * i + 1] = twoInts[i];
	      }
	    }
	    else
	    {
        int[] oneInts = new int[q];
        int[] twoInts = new int[2 * n - q];
        Array.Copy(cards, 0, oneInts, 0, q);
        Array.Copy(cards, q, twoInts, 0, 2 * n - q);
	      for (int i = 0; i < 2 * n; i++)
	      {
	        if (i < 2 * n - q)
	        {
	          cards[i] = twoInts[i];
	        }
	        else
	        {
	          cards[i] = oneInts[i - 2 * n + q];
	        }
	      }
	    }
	  }
	  for (int i = 0; i < 2 * n; i++)
	  {
	    Console.WriteLine(cards[i]);
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