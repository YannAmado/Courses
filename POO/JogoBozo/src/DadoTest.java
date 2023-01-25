import static org.junit.Assert.*;

import org.junit.After;
import org.junit.Before;
import org.junit.BeforeClass;
import org.junit.Test;

public class DadoTest {

	private static Dado novo_dado;
	
	@BeforeClass
	public static void setUp() {
		novo_dado = new Dado();
		novo_dado = new Dado(6);
	}
	
	
	@Test
	public void TestarGetLado() throws InterruptedException {
		//Testa o caso de nao ter rolado o dado antes
		assertEquals(novo_dado.getLado(), 0);
		novo_dado.rolar();
		assertTrue(novo_dado.getLado() > 0 && novo_dado.getLado() <= 6);
	}
	
	@Test
	public void TestarRolar() throws InterruptedException{
		novo_dado.rolar();
		assertTrue(novo_dado.getLado() > 0 && novo_dado.getLado() <= 6);
	}

	@Test
	public void TestartoString(){
		String dado_string[] = {
				"+-----+\n|     |\n|  *  |\n|     |\n+-----+",
				"+-----+\n|*    |\n|     |\n|    *|\n+-----+",
				"+-----+\n|*    |\n|  *  |\n|    *|\n+-----+",
				"+-----+\n|*   *|\n|     |\n|*   *|\n+-----+",
				"+-----+\n|*   *|\n|  *  |\n|*   *|\n+-----+",
				"+-----+\n|*   *|\n|*   *|\n|*   *|\n+-----+"};
		for(int i = 0; i < 6; i++) {
			novo_dado.setLado(i + 1);
			assertEquals(dado_string[i], novo_dado.toString());
		}
	}
	

}
