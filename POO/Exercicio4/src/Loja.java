import java.io.IOException;

public class Loja {
	
	
	public void adicionar_produto() throws IOException {
		Produto novo_prod;
		System.out.printf("Digite o tipo de produto (livro, CD, DVD): ");
		String tipo = EntradaTeclado.leString();
		System.out.printf("Digite o nome do produto: ");
		String nome = EntradaTeclado.leString();
		System.out.printf("Digite o codigo de barras do produto: ");
		int barcode = EntradaTeclado.leInt();
		System.out.printf("Digite a quantidade do produto: ");
		int quantidade = EntradaTeclado.leInt();
		if(tipo.equals("livro"))
			novo_prod = new Livro();
		else if(tipo.equals("CD"))
			novo_prod = new CD();
		else
			novo_prod = new DVD();
		novo_prod.adicionar_produto(nome, barcode, quantidade);
	}

	public void mostrar_todos_produtos() {
		Produto prod = new Produto();
		prod.mostrar_todos_produtos();
	}

	public void procurar_produto() throws IOException {
		Produto prod = new Produto();
		System.out.printf("Busca por codigo de barras ou nome?\n");
		String tipo = EntradaTeclado.leString();
		String chave;
		if(tipo.equals("codigo de barras")) {
			System.out.printf("Digite o codigo de barras do produto: ");
			chave = EntradaTeclado.leString();
			prod = prod.procurar_produto(Integer.parseInt(chave));
		}
		else {
			System.out.printf("Digite o nome do produto: ");
			chave = EntradaTeclado.leString();
			prod = prod.procurar_produto(chave);
		}
		if(prod == null)
			System.out.printf("Produto nao encontrado");
		else
			System.out.print(prod);
	}
	
	public void vender_produto() throws IOException {
		Produto prod = new Produto();
		System.out.printf("Digite o codigo de barras do produto: ");
		int barcode = EntradaTeclado.leInt();
		prod.vender_produto(barcode);
	}
	
}
