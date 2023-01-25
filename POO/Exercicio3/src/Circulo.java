
public class Circulo extends FiguraGeom{
	private int raio;
	
	public void setRaio(int r) {
		raio = r;
	}
	
	public int getRaio() {
		return raio;
	}
	
	public double getArea() {
		double area = Math.PI*raio*raio;
		return area;
	}

	public double getPerimetro() {
		return 2*Math.PI*raio;
	}
}
