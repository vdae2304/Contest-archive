public class Main {
	static int divisors(int n) {
		int p = 1;
		for (int i = 2; i * i <= n; i++) {
			int e = 1;
			while (n % i == 0) {
				n /= i;
				e++;
			}
			p *= e;
		}
		return n == 1 ? p : 2 * p;
	}
	
	public static void main(String[] Args) {
		int D = 500, i;
		for (i = 1; divisors(i * (i + 1) / 2) < D; i++);
		System.out.println(i * (i + 1) / 2);
	}
}
