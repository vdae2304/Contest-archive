import java.io.*;
import java.util.*;
public class Main {		
	public static void main(String[] Args) throws IOException {
		BufferedReader in = new BufferedReader(new FileReader("src/input.in"));			
		String[] v = in.readLine().split(",");				
		Arrays.sort(v);
		
		int total = 0;
		for (int i = 0; i < v.length; i++) {
			int score = 0;
			for (int j = 1; j < v[i].length() - 1; j++)
				score += v[i].charAt(j) - 'A' + 1;
			total += score * (i + 1);					
		}
		
		System.out.println(total);
	}
}
