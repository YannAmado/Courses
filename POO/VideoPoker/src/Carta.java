
public class Carta{
	public String valor_carta;
	public String naipe_carta;
	
	public void tirarCarta(){
		String[] naipes_existentes = {"♠", "♥", "♦", "♣"};
		int numero_sel;
		int naipe_sel;
		Random rand = new Random();
		try{
			Thread.sleep(50);
		}
		catch(InterruptedException e) {};
		numero_sel = 1 + rand.getIntRand(13);	//getIntRand vai de 0 ate max-1, somando 1 vai de 1 ate max
		naipe_sel = rand.getIntRand(4);
		switch(numero_sel) {
			case 1:
				valor_carta = "A";
				break;
			case 11:
				valor_carta = "J";
				break;
			case 12:
				valor_carta = "Q";
				break;
			case 13:
				valor_carta = "K";
				break;
			default:
				String.valueOf(numero_sel);
		}
		naipe_carta = naipes_existentes[naipe_sel];
		return;
	}
	
	public String toString(){
			String borda_cima =  "+-----+";
			String borda_lateral = "|      |";
			String str_final = borda_cima + "\n";
			str_final += borda_lateral + "\n";
			str_final += "| " +  valor_carta + naipe_carta + " |" + "\n";
			str_final += borda_lateral + "\n";
			str_final += borda_cima + "\n";
			return str_final;
	}
}
