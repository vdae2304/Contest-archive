public class Main {	
	public static void main(String[] Args) {
		int N = 1000, S = 0;		
		for (int i = 1; i < N; i++)
			if (i % 3 == 0 || i % 5 == 0)
				S += i;
		System.out.println(S);
	}
}
