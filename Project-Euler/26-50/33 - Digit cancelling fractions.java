public class Main {
	static boolean hasCancellation(int a, int b) {
		int x = 9 * a * b, y = 10 * a - b;
		return x % y == 0 && x / y < 10;							
	}
	
	static int mcd(int a, int b) {
		return b == 0 ? a : mcd(b, a % b);
	}
	
	public static void main(String[] Args) {
		int a = 1, b = 1;
		for (int j = 2; j < 10; j++)
			for (int i = 1; i < j; i++) 
				if (hasCancellation(i, j)) {
					a *= i;
					b *= j;
				}		
		System.out.println(b / mcd(b, a));
	}
}
