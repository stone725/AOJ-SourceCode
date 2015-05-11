using System;
using System.Collections.Generic;
using System.ComponentModel.Design;

class Program
{
  static int n, m;
  public static int Main()
  {
    Scanner cin = new Scanner();
    while (true)
    {
      n = cin.nextInt();
      m = cin.nextInt();
      if (n == 0 && m == 0)
      {
        break;
      }
      int[,] a = new int[n, m];
      for (int i = 0; i < n; i++)
      {
        for (int j = 0; j < m; j++)
        {
          a[i, j] = cin.nextInt();
        }
      }
      Console.WriteLine(dfs(a, 0));
    }
    return 0;
  }

  static int dfs(int[,] a, int now)
  {
    int res = 0;
    
    for (int i = 0; i < m; i++)
    {
      int cnt = 0;
      for (int j = 0; j < n; j++)
      {
        cnt += a[j, i];
      }
      res += Math.Max(cnt, n - cnt);
    }
    if (now == n)
    {
      return res;
    }
    res = Math.Max(res, dfs(a, now + 1));
    for (int j = 0; j < m; j++)
    {
      a[now, j] = 1 - a[now, j];
    }
    res = Math.Max(res, dfs(a, now + 1));
    return res;
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