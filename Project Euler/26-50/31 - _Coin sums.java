public class Main {
	public static void main(String[] Args) {		
		int[] coins = {1, 2, 5, 10, 20, 50, 100, 200};
		int[] DP = new int[201];
		
		DP[0] = 1;
		for (int i = 0; i < 8; i++)
			for (int j = coins[i]; j <= 200; j++)
				DP[j] += DP[j - coins[i]];
		
		System.out.println(DP[200]);
	}
}
