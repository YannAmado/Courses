import java.io.IOException;

public class Principal {

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		int op = -1;
		String chave = new String();
		String tipoChave = new String();
		while(op != 5) {
			System.out.printf("\nDigite a operacao que deseja realizar:\n");
			System.out.printf("1 - adicionar contato\n");
			System.out.printf("2 - remover contato\n");
			System.out.printf("3 - pesquisar contato\n");
			System.out.printf("4 - visualizar todos os contatos\n");
			System.out.printf("5 - sair\n");
			op = EntradaTeclado.leInt();
			switch(op) {
				case 1:
					Agenda.adicionar_pessoa();
					break;
				case 2:
					System.out.printf("Digite o tipo da chave de busca (nome, CPF, CNPJ): ");
					tipoChave = EntradaTeclado.leString();
					System.out.printf("Digite o valor: ");
					chave = EntradaTeclado.leString();
					Agenda.remover_pessoa(tipoChave, chave);
					break;
				case 3:
					System.out.printf("Digite o tipo da chave de busca (nome, CPF, CNPJ): ");
					tipoChave = EntradaTeclado.leString();
					System.out.printf("Digite o valor: ");
					chave = EntradaTeclado.leString();
					Pessoa pessoa_encontrada = Agenda.pesquisar_pessoa(tipoChave, chave);
					if(pessoa_encontrada == null)
						System.out.printf("Pessoa nao encontrada\n");
					else {
						if(pessoa_encontrada instanceof PessoaFisica)
							((PessoaFisica)pessoa_encontrada).printar_pessoa();
						else
							((PessoaJuridica)pessoa_encontrada).printar_pessoa();
					}
					break;
				case 4:
					Agenda.mostrar_todos_contatos();
					break;
			}
		}
		System.out.printf("Exit 0");
	}

}
