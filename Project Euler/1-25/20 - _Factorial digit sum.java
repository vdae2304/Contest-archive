import java.math.*;
public class Main {	
	public static void main(String[] Args) {
		int N = 100, S = 0;
		
		BigInteger p = BigInteger.ONE;
		for (int i = 2; i <= N; i++)
			p = p.multiply(BigInteger.valueOf(i));
		
		String l = p.toString();
		for (int i = 0; i < l.length(); i++)
			S += l.charAt(i) - '0';
		
		System.out.println(S);
	}
}
