
public class RolaDados {
	
	private int nDados = 5; 
	private int nlados = 6;
	private Dado[] dados = new Dado[nDados];
	int resultados[] = new int[nDados];
	
	public RolaDados(int n) {
		nDados = n;
	}
	public RolaDados() {
		nDados = 5;
	}
	
	public void setDados(int d[]) {
		for(int i = 0; i < nDados; i++) {
			dados[i].setLado(d[i]);
			resultados[i] = d[i];
		}
			
	}
	
	public int[] getDados() {
		return resultados;
	}
	
	public int[] rolar() throws InterruptedException{
		for(int i = 0; i < nDados; i++) {
			dados[i] = new Dado();
			resultados[i] = dados[i].rolar();
		}

		return resultados;
	}
	
	public int[] rolar(boolean[] quais) throws InterruptedException{
		for(int i = 0; i < quais.length; i++) {
			if(quais[i] == true)
				resultados[i] = dados[i].rolar();
		}
		
		return resultados;
	}
	
	public int[] rolar(java.lang.String s) throws InterruptedException{
		String quais[] = s.split(" ");			//Cria uma array so com os numeros
		int dado_atual;
		for(int i = 0; i < quais.length; i++) {	//ira iterar pelo numero de numeros distintos
			dado_atual = Integer.parseInt(quais[i]);//diz qual dado deve ser rolado
			if(dado_atual <= nDados)				//se o dado esta dentro do intervalo
				resultados[dado_atual-1] = dados[i].rolar();	//-1 para transformar em pos em vetor
		}
		return resultados;
	}

	public String toString(){
		String[] dado_string = {
				"+-----+\n|     |\n|  *  |\n|     |\n+-----+",
				"+-----+\n|*    |\n|     |\n|    *|\n+-----+",
				"+-----+\n|*    |\n|  *  |\n|    *|\n+-----+",
				"+-----+\n|*   *|\n|     |\n|*   *|\n+-----+",
				"+-----+\n|*   *|\n|  *  |\n|*   *|\n+-----+",
				"+-----+\n|*   *|\n|*   *|\n|*   *|\n+-----+"};
		String[][] resultado_dados = new String[5][];
		String str_final = "";
		for(int i = 0; i < nDados; i++) {
			resultado_dados[i] = dado_string[resultados[i]-1].split("\n");	//-1 para transformar de lado para pos
		}
		str_final = "1         2         3         4         5\n";
		for(int i = 0; i < 5; i++) {
			for(int j = 0; j < nDados; j++) {	//Ira concatenar os 5 dados em uma string so para ficar lado a lado
				str_final += resultado_dados[j][i];
				str_final += "   ";
			}

			str_final += "\n";
		}
		return str_final;
	}
}
