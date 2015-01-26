import java.util.Scanner;

class Main {
	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);
		while(true){
			int a = cin.nextInt();
			String s = cin.next();
			int b = cin.nextInt();
			if(s.charAt(0) == '?'){
				break;
			}
			if(s.charAt(0) == '+'){
				a += b;
			}
			if(s.charAt(0) == '-'){
				a -= b;
			}
			if(s.charAt(0) == '*'){
				a *= b;
			}
			if(s.charAt(0) == '/'){
				a /= b;
			}
			System.out.println(a);
		}
	}
}
