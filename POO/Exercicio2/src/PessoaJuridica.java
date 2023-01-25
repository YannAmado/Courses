
public class PessoaJuridica extends Pessoa{
	private String cnpj;
	private String insc_est;
	private String raz_soc;
	
	public String getCnpj() {
		return cnpj;
	}
	
	public void setCnpj(String newCnpj) {
		cnpj = newCnpj;
	}
	
	public String getInscEstad() {
		return insc_est;
	}
	
	public void setInscEstad(String newInscEst) {
		insc_est = newInscEst;
	}
	
	public String getRazSoc() {
		return raz_soc;
	}
	
	public void setRazSoc(String newRazSoc) {
		raz_soc = newRazSoc;
	}
	
	public void printar_pessoa() {
		System.out.printf("\nNome pessoa Juridica: %s\n", this.getNome());
		System.out.printf("Email: %s\n", this.getEmail());
		System.out.printf("Endereco: %s\n", this.getEndereco());
		System.out.printf("CNPJ: %s\n", this.getCnpj());
		System.out.printf("Inscricao Estadual: %s\n", this.getInscEstad());
		System.out.printf("Razao social: %s\n", this.getRazSoc());
	}
}
