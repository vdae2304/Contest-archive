public class Main {
	static boolean pentagon(int n) {
		return Math.sqrt(24 * n + 1) % 6 == 5;
	}
	
	public static void main(String[] Args) {		
		for (int i = 1; ; i++)
			for (int j = i; j > 0; j--) {
				int Pi = i * (3 * i - 1) / 2;
				int Pj = j * (3 * j - 1) / 2;
				if (pentagon(Pi + Pj) && pentagon(Pi - Pj)) {					
					System.out.println(Pi - Pj);					
					return;
				}
			}		
	}
}
