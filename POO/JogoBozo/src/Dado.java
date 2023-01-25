

public class Dado{
	private int nlados;
	private int lado_rolado = 0;
	
	public Dado(int n) {
		nlados = n;
	}
	
	public Dado() {
		nlados = 6;
	}
	
	public int getLado() {
		if(lado_rolado == 0)
			System.out.printf("Role o dado primeiro\n");
		return lado_rolado;
	}
	
	public void setLado(int lado) {
		lado_rolado = lado;
	}
	
	public int rolar() throws InterruptedException {
		Random rand = new Random();
		Thread.sleep(50);
		lado_rolado = 1 + rand.getIntRand(nlados);	//getIntRand vai de 0 ate max-1, somando 1 vai de 1 ate max
		return lado_rolado;
	}
	
	public String toString(){
		String dado_string[] = {
				"+-----+\n|     |\n|  *  |\n|     |\n+-----+",
				"+-----+\n|*    |\n|     |\n|    *|\n+-----+",
				"+-----+\n|*    |\n|  *  |\n|    *|\n+-----+",
				"+-----+\n|*   *|\n|     |\n|*   *|\n+-----+",
				"+-----+\n|*   *|\n|  *  |\n|*   *|\n+-----+",
				"+-----+\n|*   *|\n|*   *|\n|*   *|\n+-----+"};
		return dado_string[lado_rolado-1];
	}

	
}
