
public class FiguraGeom {
	private String cor;
	private boolean filled;
	
	public void setCor(String str) {
		cor = str;
	}
	
	public String getCor() {
		return cor;
	}
	
	public void setFilled(boolean f) {
		filled = f;
	}
	
	public boolean getFilled() {
		if(filled == true)
			System.out.printf("A figura eh preenchida pela cor %s\n", cor);
		else
			System.out.printf("A figura eh vazia");
		return filled;
	}
	
	public double getArea() {
		return -1;
	}

	public double getPerimetro() {
		return -1;
	}

}
