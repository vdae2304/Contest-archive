public class Main {
	static boolean isprime(int n) {	
		if (n == 1)
			return false;
		for (int i = 2; i * i <= n; i++)
			if (n % i == 0)
				return false;
		return true;
	}
	
	static boolean valid(int n) {
		for (int i = 10; i < n; i *= 10)
			if (!isprime(n % i))
				return false;
		return true;
	}
	
	static int truncate_prime(int n) {
		int S = 0;
		for (int i = 1; i < 10; i++) {
			int m = 10 * n + i;
			if (isprime(m)) {
				if (valid(m) && m > 10)					
					S += m;				
				S += truncate_prime(m);
			}
		}
		return S;
	}
		
	public static void main(String[] Args) {		
		System.out.println(truncate_prime(0));
	}
}
