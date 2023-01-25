
public class Quadrado extends FiguraGeom{
	private int lado;
	
	public void setLado(int l) {
		lado = l;
	}
	
	public int getLado() {
		return lado;
	}
	
	public double getArea() {
		return (double)lado*lado;
	}

	public double getPerimetro() {
		return (double)4*lado;
	}
	
}
