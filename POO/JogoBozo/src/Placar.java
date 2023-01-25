
public class Placar {

	private int nDados = 5;
	static private int placar[] = new int[10];
	static private int pos_ocupada[] = new int[10];
	
	public int add(int posicao, int[] dados){ 
		if(pos_ocupada[posicao-1] > 0){//se o local do placar tiver ocupado, -1 transforma de numero para posicao em vetor
			System.out.printf("Posicao ocupada\n");
			return placar[posicao-1];
		}
		
		int[] quantas_vezes_numero_aparece = new int[6];
		for(int i = 0; i < (nDados); i++) {
			quantas_vezes_numero_aparece[dados[i]-1]++;		//conta quantas vezes um resultado do dado apareceu
		}
		if(posicao >= 1 && posicao <= 6) {	//se for nas bordas
			for(int i = 0; i < nDados; i++) {
				if(dados[i] == posicao)	//se o dado tiver o mesmo resultado da posicao
					placar[posicao-1] += dados[i];
			}
		}
		else if(posicao == 7) {
			for(int i = 0; i < 6; i++) {
				if(quantas_vezes_numero_aparece[i] >= 3)
					placar[posicao-1] = 15;
			}
		}
		else if(posicao == 8) {
			placar[posicao-1] = 20;
			for(int i = 0; i < 6; i++) {
				if(quantas_vezes_numero_aparece[i] > 1)	//se encontrar algum numero repetido
					placar[posicao-1] = 0;
			}
			if(quantas_vezes_numero_aparece[0] == 1 && quantas_vezes_numero_aparece[5] == 1)//se aparece o 1 e o 6 ao mesmo tempo
				placar[posicao-1] = 0;
		}
		else if(posicao == 9) {
			for(int i = 0; i < 6; i++) {
				if(quantas_vezes_numero_aparece[i] >= 4)	//se encontrar a quadra
					placar[posicao-1] = 30;
			}
		}
		else if(posicao == 10){
			for(int i = 0; i < 6; i++) {
				if(quantas_vezes_numero_aparece[i] == 5)	//se encontrar a quina
					placar[posicao-1] = 40;
			}
		}
		//Se a posicao for ocupada por algum valor
		if(placar[posicao-1] != 0)
			pos_ocupada[posicao-1] = 1;
		return placar[posicao-1];
	}
	
	public int getScore() {	//retorna a pontuacao total
		int total = 0;
		for(int i = 0; i < 10; i++)	//10 => tamanho do placar
			total += placar[i];
		return total;
	} 
	
	public String toString() {
		String[] numero_placar = new String[10];
		for(int i = 0; i < 10; i++) {
			if(pos_ocupada[i] == 0)	//se a posicao ainda nao foi ocupada
				numero_placar[i] = "(" + (i+1) + ")";
			else {
				numero_placar[i] = String.valueOf(placar[i]) + " ";	//passa o numero como string, espaco para manter a formatacao
				if(placar[i] < 10)	//se for um numero com menos de 2 digitos ira adicionar um espaco a mais pra manter a formatacao
					numero_placar[i] += " ";
			}
				
		}

		String placar_completo = ""; 
		for(int i = 0; i < 3; i++) {
			placar_completo += numero_placar[i] + "    |   " + numero_placar[i + 6] + "    |   " + numero_placar[i + 3] + "\n";
			placar_completo += "--------------------------\n";		
		}
		placar_completo += "       |   " + numero_placar[9] + "   |\n";
		placar_completo += "       +----------+\n";
		return placar_completo;
	}
	
}
