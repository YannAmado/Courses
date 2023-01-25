
public class Poker {

	private static void trocar_cartas(PescarCartas cartas) {
		System.out.printf("Digite o numero das cartas que voce deseja trocar, separados por espaco");
		String cartas_para_mudar = "";
		try {
			cartas_para_mudar = EntradaTeclado.leString();
		}
		catch(Exception e) {}
		cartas.mudar_cartas(cartas_para_mudar);
	}
	
	private static void printar_cartas(PescarCartas cartas) {
		System.out.printf(cartas.toString());
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int creditos = 200;
		String valor_aposta = "";
		PescarCartas cartas = new PescarCartas();
		while(valor_aposta.equals('F') == false) {
			System.out.printf("Saldo atual: $%d\n", creditos);
			System.out.printf("Digite o valor da aposta ou 'F' para terminar ==> ", creditos);
			try {
				valor_aposta = EntradaTeclado.leString();
			}catch(Exception e) {}
			cartas.tirar_cartas();
			printar_cartas(cartas);
			trocar_cartas(cartas);
			trocar_cartas(cartas);
		}
	}
}
