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
	  while (true)
	  {
	    int n = cin.nextInt(), m = cin.nextInt();
	    if (n == 0 && m == 0)
	    {
	      break;
	    }
      int[] nums = new int[n];
	    for (int i = 0; i < n; i++)
	    {
	      nums[i] = cin.nextInt();
	    }
	    int ans = 0, score = 0;
	    for (int i = 0; i < n; i++)
	    {
	      if (i < m)
	      {
	        score += nums[i];
	      }
	      else
	      {
	        ans = Math.Max(ans, score);
	        score -= nums[i - m];
	        score += nums[i];
	        ans = Math.Max(ans, score);
	      }
	    }
	    Console.WriteLine(ans);
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