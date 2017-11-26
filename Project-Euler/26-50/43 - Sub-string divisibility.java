public class Main {	
	static int[] mod = {2, 3, 5, 7, 11, 13, 17};
		
	static long calculate(long n, int d, boolean[] used) {
		long sum = 0;
		if (d == 10)			
			sum += n;		
		for (int i = 0; i < 10; i++)
			if (!used[i] && (d < 3 || ((10 * n + i) % 1000) % mod[d - 3] == 0)) {
				used[i] = true;
				sum += calculate(10 * n + i, d + 1, used);
				used[i] = false;
			}
		return sum;
	}
	
	public static void main(String[] Args) {		
		System.out.println(calculate(0, 0, new boolean[10]));
	}
}
