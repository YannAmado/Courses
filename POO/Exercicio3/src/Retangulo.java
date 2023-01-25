
public class Retangulo extends FiguraGeom{
	private int base;
	private int altura;
	
	public void setBase(int lado) {
		base = lado;
	}
	
	public int getBase() {
		return base;
	}
	
	public void setAltura(int lado) {
		altura = lado;
	}
	
	public int getAltura() {
		return altura;
	}
	
	public double getArea() {
		return (double)base*altura;
	}

	public double getPerimetro() {
		int perimetro = 0;
		perimetro += base*2;
		perimetro += altura*2;
		return (double)perimetro;
	}
}
