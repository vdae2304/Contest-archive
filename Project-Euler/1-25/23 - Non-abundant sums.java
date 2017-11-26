import java.util.*;
public class Main {
	static int divisors(int n) {
		int S = 0, i;
		for (i = 1; i * i < n; i++)
			if (n % i == 0)
				S += i + n / i;
		if (n == i * i)
			S += i;
		return S;
	}
	
	public static void main(String[] Args) {
		int N = 28123, S = 0;
		
		ArrayList<Integer> abundant = new ArrayList<Integer> ();
		for (int i = 2; i <= N; i++)
			if (divisors(i) - i > i)
				abundant.add(i);
		
		boolean[] isSum = new boolean[2 * N];
		for (int i = 0; i < abundant.size(); i++)
			for (int j = i; j < abundant.size(); j++)
				isSum[abundant.get(i) + abundant.get(j)] = true;
		
		for (int i = 1; i <= N; i++)
			if (!isSum[i])
				S += i;
		
		System.out.println(S);
	}
}
