public class Main {
	static StringBuffer s = new StringBuffer("0123456789");
	
	static void swap(int i, int j) {
		char c = s.charAt(i);
		s.setCharAt(i, s.charAt(j));
		s.setCharAt(j, c);
	}
	
	static void next_permutation() {
		int i, j;
		for (i = 8; s.charAt(i) >= s.charAt(i + 1); i--);				
		for (j = 9; s.charAt(j) <= s.charAt(i); j--);
		swap(i, j);				
		for (int k = 1; k <= (10 - i) / 2; k++)
			swap(i + k, 10 - k);			
	}
	
	public static void main(String[] Args) {
		for (int i = 0; i < 999999; i++)			
			next_permutation();							
		System.out.println(s);
	}
}
