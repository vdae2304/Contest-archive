public class Main {	
	static int hasCycle(int d) {
		int m = 1;
		int[] used = new int[d];		
		for (int i = 1; m > 0; i++) {			
			m = (10 * m) % d;
			if (used[m] > 0)
				return i - m;
			used[m] = i;			
		}		
		return 0;
	}
	
	public static void main(String[] Args) {
		int d = 1, l = 0;		
		for (int i = 2; i < 1000; i++) {
			int len = hasCycle(i);
			if (len > l) {
				l = len;
				d = i;
			}
		}		
		System.out.println(d);
	}
}
