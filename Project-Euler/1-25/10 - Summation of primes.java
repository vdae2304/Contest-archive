public class Main {	
	public static void main(String[] Args) {
		int N = 2000000;
		long S = 0;
		boolean[] composite = new boolean[N];
		for (int i = 2; i < N; i++)
			if (!composite[i]) {
				S += i;
				for (int j = 2 * i; j < N; j += i)
					composite[j] = true;
			}		
		System.out.println(S);
	}
}
