//Yann Amado Nunes Costa
//N USP: 10746943


import java.io.IOException;

public class Bhaskara {
	
	static void bhaskara(double a, double b, double c) {

		double delta = b*b - 4*a*c;
		if(delta < 0) {
			System.out.print("Nao existem raizes reais\n");
			return;
		}
		double x1 = (-b + Math.sqrt(delta))/(2*a);
		double x2 =	(-b - Math.sqrt(delta))/(2*a);
		if(delta == 0)
			System.out.printf("Raiz: x = %2f\n", x1);
		else
			System.out.printf("Raizes: x1 = %2f e x2 = %2f", x1, x2);
	}
	
	

	
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		double a, b, c;
		System.out.printf("Digite o coeficiente de x^2\n");
		a = LerNumero.ler();
		System.out.printf("Digite o coeficiente de x\n");
		b = LerNumero.ler();
		System.out.printf("Digite o coeficiente livre\n");
		c = LerNumero.ler();
		bhaskara(a, b, c);
	}

}
