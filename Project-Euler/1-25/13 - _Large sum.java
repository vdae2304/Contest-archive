import java.util.*;
import java.math.*;
public class Main {
	public static void main(String[] Args) {
		Scanner sc = new Scanner(System.in);
		BigInteger S = BigInteger.ZERO;		
		for (int i = 0; i < 100; i++) 	
			S = S.add(new BigInteger(sc.nextLine()));			
		System.out.println(S.toString().substring(0, 10));
	}
}
