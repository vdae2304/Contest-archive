public class Main {	
	static boolean leapYear(int y) {
		return y % 4 == 0 && (y % 100 != 0 || y % 400 == 0);
	}
	
	public static void main(String[] Args) {
		int currentDay = 2, Sundays = 0;				
		int[] months = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
		
		for (int i = 1901; i <= 2000; i++) {
			months[1] = leapYear(i) ? 29 : 28;
			for (int j = 0; j < 12; j++) {
				if (currentDay == 0)
					Sundays++;				
				currentDay = (currentDay + months[j]) % 7;
			}
		}
		
		System.out.println(Sundays);
	}
}
