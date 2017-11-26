public class Main {
	static boolean palindrome(String s) {
		for (int i = 0; i < s.length() / 2; i++)
			if (s.charAt(i) != s.charAt(s.length() - i - 1))
				return false;
		return true;
	}
	
	public static void main(String[] Args) {
		int ans = 0;	
		for (int i = 900; i < 1000; i++)
			for (int j = 900; j < 1000; j++)
				if (palindrome(String.valueOf(i * j)))
					ans = Math.max(ans, i * j);
		System.out.println(ans);
	}
}
