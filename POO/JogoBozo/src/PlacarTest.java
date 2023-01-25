import static org.junit.Assert.*;

import org.junit.Before;
import org.junit.BeforeClass;
import org.junit.Test;

public class PlacarTest {

	static private Placar plac;
	private static int nDados;
	static String plac_str;
	
	@BeforeClass
	public static void setUp() throws Exception {
		plac = new Placar();
		nDados = 5;
		//Testa o placar no comeco
		plac_str = "(1)    |   (7)    |   (4)\n"
				+  "--------------------------\n"
				+  "(2)    |   (8)    |   (5)\n"
				+  "--------------------------\n"	
				+  "(3)    |   (9)    |   (6)\n"
				+  "--------------------------\n"
				+  "       |   (10)   |\n"
				+  "       +----------+\n";
		assertEquals(plac_str, plac.toString());
	}
	
	@Test
	public void TestarAdd() throws InterruptedException{ 
		RolaDados novos_dados = new RolaDados();
		
		int pontos;
		for(int i = 1; i <= 6; i++) {
			novos_dados.rolar();
			pontos = plac.add(i, novos_dados.getDados());
			assertTrue(pontos%i == 0);
		}
		
		//Verifica os casos dos numeros nao darem certo
		int[] dados_errados = {1, 2, 3, 4, 4};
		for(int i = 7; i <= 10; i++) {
			pontos = plac.add(i, dados_errados);
			assertTrue(pontos <= 40);
			assertTrue(pontos%5 == 0 | pontos == 0);
		}
		
		//Verifica se os casos 7, 8, 9 estao funcionando
		int[] dados = {5, 5, 5, 5, 5};
		pontos = plac.add(7, dados);
		assertTrue(pontos == 15);
		
		pontos = plac.add(9, dados);
		assertTrue(pontos == 30);
		pontos = plac.add(10, dados);
		assertTrue(pontos == 40);
		
		//Caso especifico do 8
		int[] seq_dados = {1, 2, 3, 4, 6};
		pontos = plac.add(8, seq_dados);
		assertTrue(pontos == 0 || pontos == 20);
				

		//Verifica se o caso 8 esta funcionando
		int[] seq_dados2 = {1, 2, 3, 4, 5};
		pontos = plac.add(8, seq_dados2);
		assertTrue(pontos == 20);
		
		
		//Verifica o caso de tentar adicionar em uma pontuacao que ja tenha sido ocupada
		plac.add(1, dados_errados);
		assertTrue(plac.add(1, novos_dados.getDados()) == 0 | plac.add(1, novos_dados.getDados()) < 6);
	}
	
	@Test
	public void TestargetScore() throws InterruptedException {	//retorna a pontuacao total
		TestarAdd();
		int total = plac.getScore();
		assertTrue(total > 0);
		Placar novo_plac = new Placar();
		total = novo_plac.getScore();
		assertTrue(total > 0);
	} 
	
	
	@Test
	public void TestartoString() {
		//Testa o placar no final, garantindo que ele tenha os valores dentro  
		assertFalse(plac.toString().equals(plac_str));
	}
}
