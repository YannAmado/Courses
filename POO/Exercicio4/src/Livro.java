
public class Livro extends Produto{	
	private static int n_livros = 0;
	
	public String toString() {
		String str = "";
		str += "livro: " + this.getNome() + " disponiveis: " + this.getQuantidade();
		return str;
	}
	
	public void adicionar_produto(String nome_fornecido, int barcode, int quant) {
		lista[n_prod] = new Livro();
		lista[n_prod].setNome(nome_fornecido);
		lista[n_prod].setBarCode(barcode);
		lista[n_prod].setQuantidade(quant);
		System.out.printf("produto adicionado com sucesso\n");
		n_prod++;
		n_livros++;
	}

	public static void mostrar_todos_livros() {
		System.out.printf("\nlivros diferentes existentes: %d\n", n_livros);
		for(int i = 0; i < n_prod; i++) {
			if(lista[i] instanceof Livro)	//se o produto for um livro
				System.out.println(lista[i]);
		}
	}
}
