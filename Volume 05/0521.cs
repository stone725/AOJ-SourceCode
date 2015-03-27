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
	    int ReturnMoney = 1000 - cin.nextInt();
	    if (ReturnMoney == 1000)
	    {
	      break;
	    }
	    int[] coinInts = new[] {500, 100, 50, 10, 5, 1};
	    int ans = 0;
	    for (int i = 0; i < coinInts.Length && ReturnMoney > 0; i++)
	    {
	      ans += ReturnMoney/coinInts[i];
	      ReturnMoney %= coinInts[i];
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