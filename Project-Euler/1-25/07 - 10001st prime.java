public class Main {
	static boolean prime(int p) {
		for (int i = 2; i * i <= p; i++)
			if (p % i == 0)
				return false;
		return true;
	}
	
	public static void main(String[] Args) {
		int N = 10001, i;
		for (i = 2; N > 0; i++)
			if (prime(i))
				N--;
		System.out.println(i - 1);
	}
}
