
public class PescarCartas {
	private int nCartas = 5;
	public Carta cartas[] = new Carta[nCartas];
			
	public void tirar_cartas(){
		for(int i = 0; i < 5; i++) 
			cartas[i].tirarCarta();
		return;
	}
	
	public void mudar_cartas(String s) {
		if(s.equals(""))
			return;
		String[] cartas_para_mudar = s.split(" ");
		int qual_carta;
		for(int i = 0; i < cartas_para_mudar.length; i++) {
			qual_carta = Integer.parseInt(cartas_para_mudar[i]);
			cartas[qual_carta-1].tirarCarta();	//-1 pra mudar de numero pra pos em array
		}
	}
	
	public String toString(){
			String[][] resultado_cartas = new String[nCartas][];
			String str_final = "";
			for(int i = 0; i < nCartas; i++) 
				resultado_cartas[i] = cartas[i].toString().split("\n");
			for(int i = 0; i < 5; i++) {	//5 sao quantas linhas tem no print
				for(int j = 0; j < nCartas; j++) {	//Ira concatenar as 5 cartas em uma string so para ficar lado a lado
					str_final += resultado_cartas[j][i];
					str_final += "   ";
				}
				str_final += "\n";
			}
			str_final = "(1)        (2)         (3)         (4)         (5)\n";
			return str_final;
	}
}