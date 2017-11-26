import java.math.*;
public class Main {	
	public static void main(String[] Args) {
		int N = 1000, S = 0;
		String l = BigInteger.valueOf(2).pow(N).toString();
		for (int i = 0; i < l.length(); i++)
			S += l.charAt(i) - '0';
		System.out.println(S);
	}
}
