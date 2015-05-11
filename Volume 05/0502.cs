using System;
using System.Collections.Generic;
using System.ComponentModel.Design;

class Dice
{
  public int[] dice = new[] { 1, 5, 4, 2, 3, 6 };
  public void North() {
    int tmp = dice[0];
    dice[0] = dice[3];
    dice[3] = dice[5];
    dice[5] = dice[1];
    dice[1] = tmp;
  }

  public void East() {
    int tmp = dice[0];
    dice[0] = dice[2];
    dice[2] = dice[5];
    dice[5] = dice[4];
    dice[4] = tmp;
  }

  public void South() {
    int tmp = dice[0];
    dice[0] = dice[1];
    dice[1] = dice[5];
    dice[5] = dice[3];
    dice[3] = tmp;
  }

  public void West() {
    int tmp = dice[0];
    dice[0] = dice[4];
    dice[4] = dice[5];
    dice[5] = dice[2];
    dice[2] = tmp;
  }

  public void Right() {
    int tmp = dice[1];
    dice[1] = dice[2];
    dice[2] = dice[3];
    dice[3] = dice[4];
    dice[4] = tmp;
  }

  public void Left() {
    int tmp = dice[1];
    dice[1] = dice[4];
    dice[4] = dice[3];
    dice[3] = dice[2];
    dice[2] = tmp;
  }
}


class Program
{
  
  public static int Main() {
    Scanner cin = new Scanner();
    while (true)
    {
      int ans = 1, n = cin.nextInt();
      if (n == 0)
      {
        break;
      }
      Dice dice = new Dice();
      for (int i = 0; i < n; i++)
      {
        switch (cin.next())
        {
          case "North":
            dice.North();
            break;
          case "East":
            dice.East();
            break;
          case "South":
            dice.South();
            break;
          case "West":
            dice.West();
            break;
          case "Right":
            dice.Right();
            break;
          case "Left":
            dice.Left();
            break;
        }
        ans += dice.dice[0];
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