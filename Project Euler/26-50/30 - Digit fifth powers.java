public class Main {
	static int pow5(int n) {
		return n * n * n * n * n;
	}
	
	static int SumDigits(int n) {
		int S = 0;
		while (n > 0) {
			S += pow5(n % 10);
			n /= 10;
		}
		return S;
	}
		
	public static void main(String[] Args) {		
		 int S = 0;
		 for (int i = 1000; i < 200000; i++) 
			 if (SumDigits(i) == i)
				 S += i;
		 System.out.println(S);
	}
}
