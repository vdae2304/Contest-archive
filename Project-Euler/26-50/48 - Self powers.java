public class Main {
	public static void main(String[] Args) {
		long N = 1000, M = 10000000000L, ans = 0;		
		for (int i = 1; i <= N; i++) {
			long p = 1;
			for (int j = 0; j < i; j++)
				p = (p * i) % M;
			ans = (ans + p) % M;
		}							 
		System.out.println(ans);
	}
}
