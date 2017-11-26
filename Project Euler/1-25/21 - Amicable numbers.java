public class Main {	
	static int divisors(int n) {
		int S = 0, i;
		for (i = 1; i * i < n; i++)
			if (n % i == 0)
				S += i + n / i;
		if (n == i * i)
			S += i;
		return S;
	}
	
	public static void main(String[] Args) {
		int N = 10000, S = 0;
				
		for (int i = 2; i < N; i++) {
			int j = divisors(i) - i;
			if (j < N && i != j && divisors(j) - j == i)
				S += i;
		}
				
		System.out.println(S);
	}
}
