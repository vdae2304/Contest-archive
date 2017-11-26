import java.util.*;
public class Main {
	public static void main(String[] Args) {
		Scanner sc = new Scanner(System.in);
		int ans = 0;
		int[][] grid = new int[26][26];		
		
		for (int i = 3; i < 23; i++)
			for (int j = 3; j < 23; j++)
				grid[i][j] = sc.nextInt();
		
		int[][] mov = {{0, 1}, {1, 1}, {1, 0}, {1, -1}};
		for (int k = 0; k < 4; k++)
			for (int i = 3; i < 23; i++)
				for (int j = 3; j < 23; j++) {
					int p = 1;
					for (int l = 0; l < 4; l++)
						p *= grid[i + l * mov[k][0]][j + l * mov[k][1]];
					ans = Math.max(ans, p);
				}		
		
		System.out.println(ans);		
	}
}
