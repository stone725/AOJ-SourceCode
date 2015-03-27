using System;

class Program
{
	static bool[] isNotPrime = new bool[10001]; 
	public static int Main()
	{
		//Scanner cin = new Scanner();
		isNotPrime[0] = isNotPrime[1] = true;
		for (int i = 2; i * i <= 10000; i += 2)
		{
			if (!isNotPrime[i])
			{
				for (int j = i * i; j <= 10000; j += i)
				{
					isNotPrime[j] = true;
					if (i != 2)
					{
						j += i;
					}
				}
				if (i == 2)
				{
					i--;
				}
			}
		}
		string input;
		while (!string.IsNullOrEmpty(input = Console.ReadLine()))
		{
			int n = int.Parse(input);
			int P = 0;
			for (int i = 1; i <= n; i++)
			{
				if (!isNotPrime[i] && !isNotPrime[n - i + 1])
				{
					P++;
				}
			}
			Console.WriteLine(P);
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