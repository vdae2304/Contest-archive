import java.util.*;
public class Main {
	public static void main(String[] Args) {
		int N = 1000000, p = 0, len = 0;
		ArrayList<Integer> v = new ArrayList<Integer>();
		boolean[] composite = new boolean[N];
		
		for (int i = 2; i < N; i++)
			if (!composite[i]) {
				v.add(i);
				for (int j = 2 * i; j < N; j += i)
					composite[j] = true;
			}
				
		for (int i = 0; i < v.size(); i++) {
			int S = 0;
			for (int j = i; S < N && j < v.size(); j++) {				
				if (!composite[S] && j - i > len) {
					p = S;
					len = j - i;					
				}
				S += v.get(j);
			}
		}
		
		System.out.println(p);
	}
}
