public class Main {		
	public static void main(String[] Args) {
		int N = 1000000, ans = 1;		
		StringBuffer s = new StringBuffer();
		for (int i = 1; s.length() < N; i++)
			s.append(String.valueOf(i));
		for (int i = 1; i <= N; i *= 10)
			ans *= s.charAt(i - 1) - '0';
		System.out.println(ans);
	}
}
