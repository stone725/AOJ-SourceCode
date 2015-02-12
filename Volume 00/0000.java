import java.util.Scanner;

class Main {
	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);
		solve();
	}
	
	public static void solve() {
		for(int i = 1; i <= 9; i++){
			for (int j = 1; j <= 9; j++) {
				System.out.printf("%dx%d=%d\n", i, j, i * j);
			}
		}
	}
}
