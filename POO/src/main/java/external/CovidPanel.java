package external;


public class CovidPanel {

	public static void main(String[] args) {
		Estado[] estado = new Estado[27];
		
		for(int i = 0; i <= 26; i++) {
			estado[i] = new Estado(i);
		}
		
		
	}

}
