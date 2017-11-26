public class Main {	
	static int solutions(int n) {
		int S = 0;
		for (int a = 1; a < n; a++) 
			for (int b = a; b < n; b++) {
				int c = n - a - b;
				if (a * a + b * b == c * c)
					S++;
			}
		return S;
	}
	
	public static void main(String[] Args) {
		int p = 0, max_sol = 0;		
		for (int i = 1; i <= 1000; i++) {
			int aux = solutions(i);
			if (aux > max_sol) {
				p = i;
				max_sol = aux;
			}
		}
		System.out.println(p);		
	}
}
