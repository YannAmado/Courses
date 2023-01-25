import java.io.IOException;

public class Agenda {
	
	static int n_pessoas = 0;
	static private Pessoa[] lista = new Pessoa[10000];
	static private boolean[] lRem = new boolean[10000];
	
	private static PessoaFisica montar_pessoa_fisica() throws IOException {
		PessoaFisica np = new PessoaFisica();
		System.out.printf("Digite o nome: ");
		String nome = EntradaTeclado.leString();
		System.out.printf("Digite o email: ");
		String email = EntradaTeclado.leString();
		System.out.printf("Digite o endereco: ");
		String endereco = EntradaTeclado.leString();
		System.out.printf("Digite o CPF: ");
		String cpf = EntradaTeclado.leString();
		System.out.printf("Digite a data de nascimento: ");
		String birthday = EntradaTeclado.leString();
		System.out.printf("Digite o estado civil: ");
		String estado_civil = EntradaTeclado.leString();
		np.setNome(nome);
		np.setEmail(email);
		np.setEndereco(endereco);
        np.setCpf(cpf);
        np.setDataNascimento(birthday);
        np.setEstadoCivil(estado_civil);
        return np;
	}
	
	private static PessoaJuridica montar_pessoa_juridica() throws IOException{
		PessoaJuridica np = new PessoaJuridica();
		System.out.printf("Digite o nome: ");
		String nome = EntradaTeclado.leString();
		System.out.printf("Digite o email: ");
		String email = EntradaTeclado.leString();
		System.out.printf("Digite o endereco: ");
		String endereco = EntradaTeclado.leString();
		System.out.printf("Digite o CNPJ: ");
		String cnpj = EntradaTeclado.leString();
		System.out.printf("Digite a inscricao estadual: ");
		String insc_estad = EntradaTeclado.leString();
		System.out.printf("Digite a razao social: ");
		String raz_soc = EntradaTeclado.leString();
		np.setNome(nome);
		np.setEmail(email);
		np.setEndereco(endereco);
        np.setCnpj(cnpj);
        np.setInscEstad(insc_estad);
        np.setRazSoc(raz_soc);
        return np;
	}
	
	public static void adicionar_pessoa() throws IOException {
		System.out.printf("Digite se a pessoa eh fisica ou juridica: ");
		String tipo = EntradaTeclado.leString();
		if(tipo.equals("fisica"))
			lista[n_pessoas] = montar_pessoa_fisica();
		else
			lista[n_pessoas] = montar_pessoa_juridica();
		n_pessoas++;
	}
	
	public static Pessoa pesquisar_pessoa(String tipo_pesquisa, String str) {
		if(tipo_pesquisa.equals("nome")) {
			for(int i = 0; i < n_pessoas; i++) {
				if((lista[i].getNome()).equals(str) && lRem[i] == false)	//se encontrar a pessoa e ela nao tiver sido removida 
					return lista[i];
		
			}
		}
		else if(tipo_pesquisa.equals("CPF")) {
			for(int i = 0; i < n_pessoas; i++) {
				if(lista[i] instanceof PessoaFisica && ((PessoaFisica)lista[i]).getCpf().equals(str) && lRem[i] == false)
					return lista[i];
			}
		}
		else if(tipo_pesquisa.equals("CNPJ")) {
			for(int i = 0; i < n_pessoas; i++) {
				if(lista[i] instanceof PessoaJuridica && ((PessoaJuridica)lista[i]).getCnpj().equals(str) && lRem[i] == false)
					return lista[i];
			}
		}
		return null;
	}
	
	public static void remover_pessoa(String tipo_rem, String str) {
		Pessoa pessoaRem = pesquisar_pessoa(tipo_rem, str);
		for(int i = 0; i < n_pessoas; i++) {
			if(pessoaRem == lista[i]) {
				lRem[i] = true;	
				System.out.printf("Pessoa removida com sucesso\n");
				return;
			}
		}
		System.out.printf("Pessoa nao encontrada\n");
	}
	
	public static void mostrar_todos_contatos() {
		for(int i = 0; i < n_pessoas; i++) {
			if(lRem[i] == false) {	//se o contato nao foi removido
				if(lista[i] instanceof PessoaFisica)
					((PessoaFisica)lista[i]).printar_pessoa();
				if(lista[i] instanceof PessoaJuridica)
					((PessoaJuridica)lista[i]).printar_pessoa();
			}
		}
	}

	private static void bubble() {
		int[] lista_num = new int[n_pessoas];
		for(int i = 0; i < n_pessoas; i++) {
			if(lista[i] instanceof PessoaFisica)
				lista_num[i] = Integer.parseInt(((PessoaFisica)lista[i]).getCpf());
			if(lista[i] instanceof PessoaJuridica)
				lista_num[i] = Integer.parseInt(((PessoaJuridica)lista[i]).getCnpj());
		}
		int aux;
		Pessoa auxp;
		for(int i = 0; i < n_pessoas; i++) {
			for(int j = i; j < n_pessoas; j++) {
				if(i != j && lista_num[i] > lista_num[j]) {
					//troca os numeros
					aux = lista_num[i];
					lista_num[i] = lista_num[j];
					lista_num[j] = aux;
					//troca as pessoas
					auxp = lista[i];
					lista[i] = lista[j];
					lista[j] = auxp;
				}
			}
		}
	}
	
	private static void ordenar_tipo_pessoa() {
		int np_fisicas = 0;
		int np_juridicas = 0;
		Pessoa[] lista_fisica = new Pessoa[n_pessoas];
		Pessoa[] lista_juridica = new Pessoa[n_pessoas];
		for(int i = 0; i < n_pessoas; i++) {
			if(lista[i] instanceof PessoaFisica) {
				lista_fisica[np_fisicas] = lista[i];
				np_fisicas++;
			}
			else {
				lista_juridica[np_juridicas] = lista[i];
				np_juridicas++;
			}
				
		}
		for(int i = 0; i < np_fisicas; i++)	//coloca as pessoas fisicas na frente
			lista[i] = lista_fisica[i];
		for(int i = np_fisicas; i < n_pessoas; i++)	//coloca as pessoas fisicas atras, comeca de onde o vetor anterior parou
			lista[i] = lista_juridica[i - np_fisicas];
			//i - np_fisicas para comecar do comeco da array lista_juridica
	}
	
	public static void ordena() {
		bubble();
		ordenar_tipo_pessoa();
	}
}
