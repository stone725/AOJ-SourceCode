import java.util.Scanner;

class Main {
	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);
		int n = cin.nextInt();
		int[] a = new int[n];
		for(int i = 0; i < n; i++){
			a[i] = cin.nextInt();
		}
		for (int i = 0; i < n / 2; i++) {
			int tmp = a[i];
			a[i] = a[n - i - 1];
			a[n - i - 1] = tmp;
		}
		for (int i = 0; i < n - 1; i++) {
			System.out.printf("%d ", a[i]);
		}
		System.out.println(a[n - 1]);
	}
}
