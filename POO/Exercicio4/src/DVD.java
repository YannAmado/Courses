
public class DVD extends Produto{
	private static int n_dvds = 0;
	
	public String toString() {
		String str = "";
		str += "DVD: " + this.getNome() + " disponiveis: " + this.getQuantidade();
		return str;
	}
	
	public void adicionar_produto(String nome_fornecido, int barcode, int quant) {
		lista[n_prod] = new DVD();
		lista[n_prod].setNome(nome_fornecido);
		lista[n_prod].setBarCode(barcode);
		lista[n_prod].setQuantidade(quant);
		System.out.printf("produto adicionado com sucesso\n");
		n_prod++;
		n_dvds++;
	}

	public static void mostrar_todos_dvds() {
		System.out.printf("\nDVDs diferentes existentes: %d\n", n_dvds);
		for(int i = 0; i < n_prod; i++) {
			if(lista[i] instanceof DVD)	//se o produto for um livro
				System.out.println(lista[i]);
		}
	}
}
