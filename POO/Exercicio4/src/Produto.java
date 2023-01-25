import java.io.IOException;

public class Produto {
	protected static Produto[] lista = new Produto[10000];
	protected static int n_prod = 0;
	private int bar_code;
	private String nome;
	private int quantidade;

	protected void increase_n_prod() {	
		n_prod++;
	}
	
	protected int getNProd() {
		return n_prod;
	}
	
	protected void setBarCode(int barcode) {
		bar_code = barcode;
	}
	
	protected int getBarCode() {
		return bar_code;
	}
	
	protected void setNome(String str) {
		nome = str;
	}
	
	protected String getNome() {
		return nome;
	}
	
	protected void setQuantidade(int quant) {
		quantidade = quant;
	}
	
	protected int getQuantidade() {
		return quantidade;
	}
	
	public void adicionar_produto(String nome_fornecido, int barcode, int quant) {
		lista[n_prod].setNome(nome_fornecido);
		lista[n_prod].setBarCode(barcode);
		lista[n_prod].setQuantidade(quant);
		System.out.printf("produto adicionado com sucesso\n");
		n_prod++;
	}
	
	public void mostrar_todos_produtos() {
		Livro.mostrar_todos_livros();
		CD.mostrar_todos_cds();
		DVD.mostrar_todos_dvds();;
	}
	
	public Produto procurar_produto(String str) {
		for(int i = 0; i < n_prod; i++) {
			if(str.equals(lista[i].getNome())) {
				return lista[i];
			}
		}
		return null;
	}
	
	public Produto procurar_produto(int barcode) {
		for(int i = 0; i < n_prod; i++) {
			if(barcode == lista[i].getBarCode()) {
				return lista[i];
			}
		}
		return null;
	}

	public void vender_produto(int barcode) throws IOException {
		Produto prod = procurar_produto(barcode);
		System.out.println(prod);
		System.out.println("Quantos produtos deseja comprar?");
		int quant = EntradaTeclado.leInt();
		if(quant > prod.quantidade)
			System.out.println("A quantidade pedida excede o estoque");
		else {
			prod.quantidade -= quant;
			System.out.println("Produto vendido com sucesso");
		}
	}
	
}
