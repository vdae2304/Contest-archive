public class Main {		
	public static void main(String[] Args) {		
		int N = 100, M = 1000000, ans = 0;
		int[][] choose = new int[N + 1][N + 1];
		for (int i = 1; i <= N; i++) {
			choose[i][0] = choose[i][i] = 1;
			for (int j = 1; j < i; j++) {
				choose[i][j] = Math.min(M + 1, choose[i - 1][j - 1] + choose[i - 1][j]);
				if (choose[i][j] > M)
					ans++;									
			}
		}
		System.out.println(ans);
	}
}
