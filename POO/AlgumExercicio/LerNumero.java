//Yann Amado Nunes Costa
//N USP: 10746943


import java.io.IOException;

public class LerNumero {
	public static double ler() throws IOException{
		double coeficiente = 0;
		boolean leu = false;
		while(!leu) {
			leu = true;
			try {
				coeficiente = EntradaTeclado.leDouble();
			}catch(Exception e){
				System.out.printf("O item escrito nao eh um numero, digite novamente\n");
				leu = false;
			}
		}
		return coeficiente;
	}

}
