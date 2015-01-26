import java.util.Scanner;

class Main {
	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);
		String str = "SHCD";
		int n = cin.nextInt();
		boolean[][] noGet = new boolean[4][13];
		for(int i = 0; i < 4; i++){
			for(int j = 0; j < 13; j++){
				noGet[i][j] = true;
			}
		}
		for(int i = 0; i < n; i++){
			String s = cin.next();
			int num = cin.nextInt() - 1;
			noGet[str.indexOf(s)][num] = false;
		}
		for(int i = 0; i < 4; i++){
			for(int j = 0; j < 13; j++){
				if(noGet[i][j]){
					System.out.printf("%c %d\n", str.charAt(i), j + 1);
				}
			}
		}
	}
}
