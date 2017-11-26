public class Main {
	static boolean prime(int n) {
		for (int i = 2; i * i <= n; i++)
			if (n % i == 0)
				return false;
		return true;
	}
	
	public static void main(String[] Args) {		
		for (int i = 3; ; i += 2) 
			if (!prime(i)) {
				boolean counterexample = true;
				for (int j = 3; j < i; j += 2)
					if (prime(j) && Math.sqrt((i - j) / 2) % 1 == 0) {
						counterexample = false;
						break;
					}
				if (counterexample) {
					System.out.println(i);
					return;
				}
			}
	}
}
