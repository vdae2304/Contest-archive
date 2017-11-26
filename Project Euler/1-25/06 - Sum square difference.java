public class Main {
	public static void main(String[] Args) {
		int N = 100;
		int Sa = N * (N + 1) / 2;
		int Sb = N * (N + 1) * (2 * N + 1) / 6;
		System.out.println(Sa * Sa - Sb);
	}
}
