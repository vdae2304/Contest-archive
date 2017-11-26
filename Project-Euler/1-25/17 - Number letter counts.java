public class Main {	
	public static void main(String[] Args) {
		int S = 11;
		
		int[] units = {0, 3, 3, 5, 4, 4, 3, 5, 5, 4, 3, 6, 6, 8, 8, 7, 7, 9, 8, 8};
		int[] tens = {0, 0, 6, 6, 5, 5, 5, 7, 6, 6};
		int[] hundreds = {0, 13, 13, 15, 14, 14, 13, 15, 15, 14};		 
		
		for (int i = 0; i < 1000; i += 100) {
			if (i > 0)
				S -= 3;
			for (int j = 0; j < 20; j++)
				S += hundreds[i / 100] + units[j];
			for (int j = 20; j < 100; j++)
				S += hundreds[i / 100] + tens[j / 10] + units[j % 10];
		}
		
		System.out.println(S);
	}
}
