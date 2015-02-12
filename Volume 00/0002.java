import java.util.Scanner;

class Main {
	public static int a, b;
	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);
		while(cin.hasNextInt()){
			a = cin.nextInt();
			b = cin.nextInt();
			solve();
		}
	}
	
	public static void solve() {
		a += b;
		int ans = 1;
		while(a / 10 > 0){
			a /= 10;
			ans++;
		}
		System.out.println(ans);
	}
}
