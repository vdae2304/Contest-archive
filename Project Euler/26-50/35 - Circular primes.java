public class Main {
	static int N = 1000000;
	static boolean[] composite = new boolean[N];
	
	static boolean circular(char[] s) {	
		for (int i = 0; i < s.length; i++) {
			char c = s[0];
			for (int j = 0; j < s.length - 1; j++)
				s[j] = s[j + 1];
			s[s.length - 1] = c;			
			if (composite[Integer.parseInt(new String(s))])
				return false;
		}
		return true;			
	}
	
	public static void main(String[] Args) {		
		for (int i = 2; i < N; i++)
			if (!composite[i]) 
				for (int j = 2 * i; j < N; j += i)
					composite[j] = true;			
		
		int S = 0;
		for (int i = 2; i < N; i++)
			if (circular(String.valueOf(i).toCharArray()))				
				S++;			
		System.out.println(S);		
	}
}
