//Yann Amado Nunes Costa
//N USP: 10746943


import java.io.IOException;

public class RaizQuadrada {

	static double raizQuadrada(double numero, double x0){
		double div = numero/x0;
		double xi = (x0 + div)/2;
		if(x0 - xi <= 0.00000001)
			return xi;
		else
			return raizQuadrada(numero, xi);
	}


	
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		double numero, x0;
		System.out.printf("Digite o numero\n");
		numero = LerNumero.ler();
		System.out.printf("Digite o x0\n");
		x0 = LerNumero.ler();
		System.out.printf("%2f\n", raizQuadrada(numero, x0));
	}

}
