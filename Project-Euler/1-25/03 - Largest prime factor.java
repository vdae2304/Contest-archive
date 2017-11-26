public class Main {	
	public static void main(String[] Args) {
		long N = 600851475143L;
		for (long i = 2; i * i < N; i++) 
			while (N % i == 0)
				N /= i;			
		System.out.println(N);
	}
}
