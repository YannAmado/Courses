import java.io.IOException;

public class Principal {

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		System.out.printf("\nO que deseja calcular?\n");
		System.out.printf("1 - Area\n");
		System.out.printf("2 - Perimetro\n");
		int op = EntradaTeclado.leInt();
		System.out.printf("Qual figura geometrica?\n");
		System.out.printf("1 - Quadrado\n");
		System.out.printf("2 - Retangulo\n");
		System.out.printf("3 - Circulo\n");
		int fig = EntradaTeclado.leInt();
		System.out.printf("Digite a cor: ");
		String cor = EntradaTeclado.leString();
		System.out.printf("Digite se eh preenchido (true/false): ");
		String filled = EntradaTeclado.leString();
		FiguraGeom figura;
		switch(fig) {
			case 1:
				Quadrado quad = new Quadrado();
				System.out.printf("Digite a medida do lado: ");
				int lado = EntradaTeclado.leInt();
				quad.setLado(lado);
				figura = quad;
				break;
			case 2:
				Retangulo ret = new Retangulo();
				System.out.printf("Digite a medida da base: ");
				int base = EntradaTeclado.leInt();
				System.out.printf("Digite a medida da altura: ");
				int altura = EntradaTeclado.leInt();
				ret.setAltura(altura);
				ret.setBase(base);
				figura = ret;
				break;
			default:
				System.out.printf("Digite o valor do raio: ");
				int raio = EntradaTeclado.leInt();
				Circulo circ = new Circulo();
				circ.setRaio(raio);
				figura = circ;
				break;
		}
		figura.setCor(cor);
		figura.setFilled(Boolean.parseBoolean(filled));
		if(op == 1) {
			System.out.print("Area: ");
			System.out.print(figura.getArea());
			System.out.print(" cor: ");
			System.out.println(figura.getCor());
			figura.getFilled();
		}
			
		else
			System.out.print("Perimetro: ");
			System.out.print(figura.getPerimetro());
			System.out.print(" cor: ");
			System.out.println(figura.getCor());
			figura.getFilled();
	}
}