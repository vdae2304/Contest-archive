public class Main {
	public static void main(String[] Args) {		
		int N = 1001, S = 1;
		for (int i = 3; i <= N; i += 2)
			for (int j = 0; j < 4; j++)
				S += i * i - j * (i - 1);
		System.out.println(S);
	}
}
