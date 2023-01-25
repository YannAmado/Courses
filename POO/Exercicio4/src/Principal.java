import java.io.IOException;

public class Principal {

	public static Loja minha_loja = new Loja();
	
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		int op = -1;
		while(op != 5) {
			System.out.printf("\nDigite a operacao que deseja realizar:\n");
			System.out.printf("1 - adicionar produto\n");
			System.out.printf("2 - vender produto\n");
			System.out.printf("3 - pesquisar produto\n");
			System.out.printf("4 - visualizar todos os produtos\n");
			System.out.printf("5 - sair\n");
			op = EntradaTeclado.leInt();
			switch(op) {
				case 1:
					minha_loja.adicionar_produto();
					break;
				case 2:
					minha_loja.vender_produto();
					break;
				case 3:
					minha_loja.procurar_produto();
					break;
				case 4:
					minha_loja.mostrar_todos_produtos();
					break;
			}
		}
		System.out.printf("Exit 0");
	}

}
