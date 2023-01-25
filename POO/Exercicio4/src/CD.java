
public class CD extends Produto{
	private static int n_cds = 0;
	
	public String toString() {
		String str = "";
		str += "CD: " + this.getNome() + " disponiveis: " + this.getQuantidade();
		return str;
	}
	
	public void adicionar_produto(String nome_fornecido, int barcode, int quant) {
		lista[n_prod] = new CD();
		lista[n_prod].setNome(nome_fornecido);
		lista[n_prod].setBarCode(barcode);
		lista[n_prod].setQuantidade(quant);
		System.out.printf("produto adicionado com sucesso\n");
		n_prod++;
		n_cds++;
	}

	public static void mostrar_todos_cds() {
		System.out.printf("\nCDs diferentes existentes: %d\n", n_cds);
		for(int i = 0; i < n_prod; i++) {
			if(lista[i] instanceof CD)	//se o produto for um livro
				System.out.println(lista[i]);
		}
	}

}
