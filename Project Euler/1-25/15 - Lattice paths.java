public class Main {	
	public static void main(String[] Args) {
		int N = 21;
		long[][] grid = new long[N + 1][N + 1];

		grid[1][1] = 1;
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				grid[i][j] += grid[i - 1][j] + grid[i][j - 1];
				
		System.out.println(grid[N][N]);
	}
}
