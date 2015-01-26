import java.util.Arrays;
import java.util.Scanner;

class Main {
	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);
		int[] a = new int[2];
		while(true){
			for(int i = 0; i < 2; i++){
				a[i] = cin.nextInt();
			}
			if( a[0] == 0 && a[1] == 0 ){
				break;
			}
			Arrays.sort(a);
			System.out.printf("%d %d\n", a[0], a[1]);
		}
	}
}
