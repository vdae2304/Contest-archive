public class Main {
	static int N = 1000000;
	static int[] DP = new int[N];
	
	static int Collatz(long n) {
		long m = n % 2 == 0 ? n / 2 : 3 * n + 1;
		if (n >= N)
			return Collatz(m) + 1;
		else if (DP[(int) n] == 0)
			DP[(int) n] = Collatz(m) + 1;
		return DP[(int) n];
	}
	
	public static void main(String[] Args) {
		int ans = 1;
		
		DP[1] = 1;
		for (int i = 2; i < N; i++)
			if (Collatz(i) > DP[ans])
				ans = i;
		
		System.out.println(ans);
	}
}
