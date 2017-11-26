import java.math.*;
public class Main {
	public static void main(String[] Args) {
		int i;		
		BigInteger a = BigInteger.ONE, b = a, c = BigInteger.valueOf(2);
		for (i = 1; a.toString().length() < 1000; i++) {
			a = b;
			b = c;
			c = a.add(b);
		}
		System.out.println(i);		
	}
}
