public class Main {
	public static void main(String[] Args) {
		int p = 0;
		for (int a = 1; a < 1000; a++)
			for (int b = a; a + b < 1000; b++) {
				int c = 1000 - a - b;
				if (a * a + b * b == c * c)
					p = a * b * c;
			}
		System.out.println(p);
	}
}
