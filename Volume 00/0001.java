import java.util.Arrays;
import java.util.Scanner;

class Main {
	public static int[] a = new int[10];
	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);
		for (int i = 0; i < a.length; i++) {
			a[i] = cin.nextInt();
		}
		solve();
	}
	
	public static void solve() {
		Arrays.sort(a);
		for(int i = a.length - 1; i > 6; i--){
			System.out.println(a[i]);
		}
	}
}
