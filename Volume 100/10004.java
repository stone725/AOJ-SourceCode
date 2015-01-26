import java.util.Arrays;
import java.util.Scanner;

class Main {
	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);
		int[] a = new int[3];
		for(int i = 0; i < 3; i++){
			a[i] = cin.nextInt();
		}
		Arrays.sort(a);
		System.out.printf("%d %d %d\n", a[0], a[1], a[2]);
	}
}
