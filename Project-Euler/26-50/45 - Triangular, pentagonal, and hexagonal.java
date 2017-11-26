public class Main {	
	public static void main(String[] Args) {		
		for (int i = 144; ; i++) {
			long n = i * (2 * i - 1);
			if (Math.sqrt(24 * n + 1) % 6 == 5) {
				System.out.println(n);
				return;
			}
		}
	}
}
