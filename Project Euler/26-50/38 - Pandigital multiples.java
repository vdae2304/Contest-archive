public class Main {
	static boolean pandigital(StringBuffer s) {
		int[] used = new int[10];
		for (int i = 0; i < s.length(); i++)
			used[s.charAt(i) - '0']++;
		for (int i = 1; i < 10; i++)
			if (used[i] != 1)
				return false;
		return true;
	}
	
	public static void main(String[] Args) {
		int ans = 0;
		for (int i = 1; i < 10000; i++) {
			StringBuffer s = new StringBuffer();
			for (int j = 1; s.length() < 9; j++)
				s.append(String.valueOf(i * j));
			if (s.length() == 9 && pandigital(s))
				ans = Math.max(ans, Integer.parseInt(s.toString()));
		}
		System.out.println(ans);
	}
}
