import java.util.Scanner;

class Main {
	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);
		int a = cin.nextInt(), b = cin.nextInt(); 
		System.out.print( "a" );
		if( a < b ){
			System.out.print( " < " );
		}
		else if( a > b ){
			System.out.print( " > " );
		}
		else{
			System.out.print( " == " );
		}
		System.out.println( "b" );
	}
}
