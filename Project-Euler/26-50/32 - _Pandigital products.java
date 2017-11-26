public class Main {
	static boolean pandigital(StringBuffer s) {
		int[] use = new int[10];
		for (int i = 0; i < s.length(); i++)
			use[s.charAt(i) - '0']++;
		for (int i = 1; i < 10; i++)
			if (use[i] != 1)
				return false;		
		return use[0] == 0;
	}
	
	static boolean check(int a, int b, int p) {
		StringBuffer s = new StringBuffer(String.valueOf(a));
		s.append(String.valueOf(b));
		s.append(String.valueOf(p));
		return pandigital(s);
	}
	
	public static void main(String[] Args) {		
		long S = 0;
		for (int i = 1; i < 10000; i++) {
			for (int j = 1; j * j <= i; j++)
				if (i % j == 0 && check(j, i / j, i)) {
					S += i;
					break;
				}
		}		
		System.out.println(S);
	}
}
