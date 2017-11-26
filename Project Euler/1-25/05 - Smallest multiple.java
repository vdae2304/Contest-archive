public class Main {
	static long gcd(long a, long b) {
		return b == 0 ? a : gcd(b, a % b);
	}
	
	public static void main(String[] Args) {
		long p = 1;
		for (int i = 1; i <= 20; i++)
			p = (p * i) / gcd(p, i);
		System.out.println(p);
	}
}
