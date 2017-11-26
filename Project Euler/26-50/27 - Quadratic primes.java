public class Main {
	static boolean[] prime = new boolean[15000];
	
	static boolean isprime(int n) {
		for (int i = 2; i * i <= n; i++)
			if (n % i == 0)
				return false;
		return true;
	}
	
	static int f(int n, int a, int b) {
		return n * n + a * n + b;
	}
	
	public static void main(String[] Args) {		
		for (int i = 2; i < 15000; i++)
			prime[i] = isprime(i);
		
		int ans = 0, l = 0, i;		
		for (int a = -999; a < 1000; a++)
			for (int b = -999; b < 1000; b++) {				
				for (i = 0; f(i, a, b) > 0 && prime[f(i, a, b)]; i++);
				if (i > l) {
					l = i;
					ans = a * b;
				}
			}
		
		System.out.println(ans);
	}
}
