public class Main {	
	public static void main(String[] Args) {
		int N = 4000000, S = 0;		
		for (int a = 1, b = 2, c = 3; a <= N; a = b, b = c, c = a + b)
			if (a % 2 == 0)
				S += a;
		System.out.println(S);
	}
}
