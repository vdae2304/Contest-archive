public class Main {
	static boolean prime(int n) {		
		for (int i = 2; i * i <= n; i++)
			if (n % i == 0)
				return false;
		return true;
	}
	
	static boolean pandigital(int d, boolean used[]) {
		for (int i = 1; i <= d; i++)
			if (!used[i])
				return false;
		return true;
	}
	
	static int calculate(int n, int d, boolean used[]) {
		int largest = 0;		
		if (prime(n) && pandigital(d, used))
			largest = n;
		for (int i = 1; i < 8; i++)
			if (!used[i]) {
				used[i] = true;
				largest = Math.max(largest, calculate(10 * n + i, d + 1, used));
				used[i] = false;
			}
		return largest;
	}
	
	public static void main(String[] Args) {
		System.out.println(calculate(0, 0, new boolean[8]));
	}
}
