import java.util.Scanner;

class Main {
	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);
		boolean many_case = false;
		while( true ){
			int a = cin.nextInt(), b = cin.nextInt();
			if(a == 0 && b == 0){
				break;
			}
			many_case = true;
			for(int i = 0; i < a; i++){
				for(int j = 0; j < b; j++){
					System.out.print("#");
				}
				System.out.println();
			}
			System.out.println();
		}
	}
}
