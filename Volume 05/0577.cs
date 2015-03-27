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
	  int[][] array = new int[3][];
	  int n = cin.nextInt();
	  for (int i = 0; i < 3; i++)
	  {
	    array[i] = new int[n];
	  }
	  for (int i = 0; i < n; i++)
	  {
	    for (int j = 0; j < 3; j++)
	    {
	      array[j][i] = cin.nextInt();
	    }
	  }
    int[] score = new int[n];
	  for (int i = 0; i < 3; i++)
	  {
	    for (int j = 0; j < n; j++)
	    {
        if (Array.IndexOf(array[i], array[i][j]) == Array.LastIndexOf(array[i], array[i][j]))
	      {
	        score[j] += array[i][j];
	      }
	    }
	  }
	  for (int i = 0; i < n; i++)
	  {
	    Console.WriteLine(score[i]);
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