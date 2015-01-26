import java.util.Scanner;

class Main {
	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);
		int cnt = 1;
		int a;
		while(true){
			a = cin.nextInt();
			if(a == 0){
				break;
			}
			System.out.printf("Case %d: %d\n", cnt, a);
			cnt++;
		}
	}
}
