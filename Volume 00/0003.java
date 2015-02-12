import java.util.Arrays;
import java.util.Scanner;

class Main {
	public static int[] a = new int[3];
	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);
		int n = cin.nextInt();
		while(0 != n--){
			for (int i = 0; i < a.length; i++) {
				a[i] = cin.nextInt();
			}
			solve();
		}
	}
	
	public static void solve() {
		Arrays.sort(a);
		System.out.println(a[0] * a[0] + a[1] * a[1] == a[2] * a[2] ? "YES" : "NO");
	}
}
