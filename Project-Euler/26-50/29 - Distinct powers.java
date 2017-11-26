import java.util.*;
import java.math.*;
public class Main {		
	public static void main(String[] Args) {		
		Set<BigInteger> v = new HashSet<BigInteger>();
		for (int i = 2; i <= 100; i++) {
			BigInteger n = BigInteger.valueOf(i);
			for (int j = 2; j <= 100; j++) {
				n = n.multiply(BigInteger.valueOf(i));
				v.add(n);
			}
		}
		System.out.println(v.size());
	}
}
