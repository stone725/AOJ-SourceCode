import java.util.Scanner;

class Main {
	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);
		int a = cin.nextInt(), b = cin.nextInt(); 
		System.out.printf("%d %d\n", a * b, a * 2 + b * 2);
	}
}
