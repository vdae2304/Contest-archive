public class Main {
	static int factorial(int n) {
		int p = 1;
		for (int i = 2; i <= n; i++)
			p *= i;
		return p;
	}
	
	static int sum(int n) {
		int S = 0;
		while (n > 0) {
			S += factorial(n % 10);
			n /= 10;
		}
		return S;
	}
	
	public static void main(String[] Args) {		
		int S = 0;
		for (int i = 10; i < 100000; i++)
			if (sum(i) == i)
				S += i;
		System.out.println(S);
	}
}
