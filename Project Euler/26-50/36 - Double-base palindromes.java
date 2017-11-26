public class Main {
	static boolean palindrome(String s) {
		for (int i = 0; i < s.length() / 2; i++)
			if (s.charAt(i) != s.charAt(s.length() - i - 1))
				return false;
		return true;
	}
	
	public static void main(String[] Args) {		
		int N = 1000000, S = 0;
		for (int i = 1; i < N; i++)
			if (palindrome(Integer.toString(i)) && palindrome(Integer.toBinaryString(i)))
				S += i;				
		System.out.println(S);
	}
}
