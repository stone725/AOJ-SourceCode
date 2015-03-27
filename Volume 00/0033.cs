using System;
using System.Collections.Generic;

class Program {
	static int[] array = new int[10];
	public static int Main()
	{
		int n = int.Parse(Console.ReadLine());
		while (n-- != 0)
		{
			string[] input = Console.ReadLine().Split(' ');
			for (int i = 0; i < 10; i++)
			{
				array[i] = int.Parse(input[i]);
			}
			Console.WriteLine(is_can(0, 0, 0) ? "YES" : "NO");
		}
		return 0;
	}

	static bool is_can(int left, int right, int now)
	{
		if (now == array.Length)
		{
			return true;
		}
		if (left < array[now] && is_can(array[now], right, now + 1))
		{
			return true;
		}
		if (right < array[now] && is_can(left, array[now], now + 1)) {
			return true;
		}
		return false;
	}
}