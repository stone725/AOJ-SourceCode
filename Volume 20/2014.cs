using System;
using System.Collections.Generic;
using System.ComponentModel.Design;

class Program {
  static int n, m;
  static char[][] map;
  private static readonly int[] dy = new[] {1, -1, 0, 0};
  private static readonly int[] dx = new[] {0, 0, 1, -1};
  public static int Main() {
    Scanner cin = new Scanner();
    while (true)
    {
      n = cin.nextInt();
      m = cin.nextInt();
      if (n == 0 && m == 0)
      {
        break;
      }
      map = new char[m][];
      for (int i = 0; i < m; i++)
      {
        map[i] = cin.next().ToCharArray();
      }
      int b = 0, w = 0;
      for (int i = 0; i < m; i++)
      {
        for (int j = 0; j < n; j++)
        {
          if (map[i][j] == '.')
          {
            char color = getColor(j, i);
            if (color == 'B')
            {
              b += dfs(j, i, color);
            }
            if (color == 'W')
            {
              w += dfs(j, i, color);
            }
          }
        }
      }
      Console.WriteLine("{0} {1}", b, w);
    }
    return 0;
  }

  private static char getColor(int nowx, int nowy)
  {
    if (map[nowy][nowx] != '.')
    {
      return map[nowy][nowx];
    }
    map[nowy][nowx] = 'C';
    char res = '.';
    for (int i = 0; i < 4; i++)
    {
      if (nowy + dy[i] < 0 || nowy + dy[i] == m || nowx + dx[i] < 0 || nowx + dx[i] == n || map[nowy + dy[i]][nowx + dx[i]] == 'C')
      {
        continue;
      }
      char c = getColor(nowx + dx[i], nowy + dy[i]);
      if ((res != '.' && res != c && c != '.') || c == 'e')
      {
        res = 'e';
      }
      else if(c != '.')
      {
        res = c;
      }
    }
    return res;
  }

  private static int dfs(int nowx, int nowy, char color)
  {
    if (map[nowy][nowx] != 'C')
    {
      return 0;
    }
    map[nowy][nowx] = color;
    int res = 1;
    for (int i = 0; i < 4; i++)
    {
      if (nowy + dy[i] < 0 || nowy + dy[i] == m || nowx + dx[i] < 0 || nowx + dx[i] == n) {
        continue;
      }
      res += dfs(nowx + dx[i], nowy + dy[i], color);
    }
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