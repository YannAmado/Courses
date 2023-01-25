

public class Bozo {
	static Placar placar_atual = new Placar();
	static RolaDados rola_dados = new RolaDados(5);

	
	private static int reroll(){
		String str_lida = "";
		String[] quais_dados;
		System.out.printf("Digite o numero dos dados que quiser TROCAR. Separados por espaco.\n");
		try {
			str_lida = EntradaTeclado.leString();
		}
		catch(Exception e) {}
		if(str_lida.equals(""))
			return 0;
		quais_dados = str_lida.split(" ");
		if(quais_dados.length > 0 && quais_dados[0].equals("true") || quais_dados[0].equals("false")) {	//se for um booleano
			boolean[] dados_bool = new boolean[5];
			for(int i = 0; i < quais_dados.length; i++) {
				if(quais_dados[i].equals("true"))
					dados_bool[i] = true;
				else
					dados_bool[i] = false;
			}
			try {
				rola_dados.rolar(dados_bool);
			}catch(InterruptedException  e) {}
			
		}
		else {
			try {
				rola_dados.rolar(str_lida);
			}catch(InterruptedException  e) {}
		}
		return 1;
	}
	
	
	private static void printar_dados() {
		System.out.printf("%s\n", rola_dados.toString());	//printa o resultado dos dados
	}
	

	public static void main(String[] args){
		// TODO Auto-generated method stub

		int pos_placar = -1;
		int decisao;
		System.out.printf(placar_atual.toString());
		for(int i = 0; i < 10; i++) {
			System.out.printf("****** Rodada %d\n", i+1);
			System.out.printf("Pressione ENTER para lancar os dados\n");
			try {
				EntradaTeclado.leString();
			}
			catch(Exception e) {}
			try {
				rola_dados.rolar();	//rola todos os dados
			}catch(InterruptedException  e) {}
			printar_dados();
			decisao = reroll();
			if(decisao == 1) { 	//se a pessoa havia decidido manter antes
				printar_dados();
				decisao = reroll();
				if(decisao == 1)
					printar_dados();
			}
			System.out.printf("\n\n\n");
			System.out.printf(placar_atual.toString());
			System.out.printf("Escolha a posicao que quer ocupar com essa jogada ===> ");
			System.out.printf("\n");
			try {
				pos_placar = EntradaTeclado.leInt();
			}
			catch(Exception e) {}
			placar_atual.add(pos_placar, rola_dados.resultados);
			System.out.printf(placar_atual.toString());
		}
		System.out.printf("pontuacao total: %d", placar_atual.getScore());
	}

}
