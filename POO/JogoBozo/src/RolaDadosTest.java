import static org.junit.Assert.*;

import org.junit.Before;
import org.junit.BeforeClass;
import org.junit.Test;

public class RolaDadosTest {
	
	private static RolaDados dados;
	private static int nDados = 5;
	
	@BeforeClass
	public static void setUp() throws Exception {
		dados = new RolaDados();
		dados = new RolaDados(nDados);
	}
	
	@Test
	public void TestarRolar() throws InterruptedException{
		int resultados[];
		resultados = dados.rolar();
		boolean quais_bool[] = {true, true, false, false, true}; 
		dados.rolar(quais_bool);
		for(int i = 0; i < nDados; i++) {
			if(!quais_bool[i])
				assertTrue(resultados[i] == (dados.getDados())[i]);
		}
		String quais_str = "1 4 7";
		resultados = dados.rolar();
		dados.rolar(quais_str);
		for(int i = 0; i < nDados; i++) {
			if(i != 0 & i != 3)
				assertTrue(resultados[i] == (dados.getDados())[i]);
		}
	}
	
	@Test
	public void TestartoString(){
		int d[] = {1, 1, 3, 5, 4, 6};
		dados.setDados(d);
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
			resultado_dados[i] = dado_string[d[i]-1].split("\n");	//-1 para transformar de lado para pos
		}
		str_final = "1         2         3         4         5\n";
		for(int i = 0; i < 5; i++) {
			for(int j = 0; j < nDados; j++) {	//Ira concatenar os 5 dados em uma string so para ficar lado a lado
				str_final += resultado_dados[j][i];
				str_final += "   ";
			}

			str_final += "\n";
		}
		assertEquals(str_final, dados.toString());
	}
}
