import java.io.*;
public class Main {
	public static void main(String[] Args) throws IOException {
		BufferedReader in = new BufferedReader(new FileReader("src/input.in"));
		int ans = 0;
		String[] v = in.readLine().split(",");
		
		for (int i = 0; i < v.length; i++) {
			int S = 0;
			for (int j = 1; j < v[i].length() - 1; j++)
				S += v[i].charAt(j) - 'A' + 1;
			if (Math.sqrt(8 * S + 1) % 2 == 1)
				ans++;
		}
		
		System.out.println(ans);
	}
}
