
public class PessoaFisica extends Pessoa{
	private String cpf;
	private String birthday;
	private String estado_civil;
	
	public String getCpf() {
		return cpf;
	}
	
	public void setCpf(String newCpf) {
		cpf = newCpf;
	}
	
	public String getDataNascimento() {
		return birthday;
	}
	
	public void setDataNascimento(String newBirthday) {
		birthday = newBirthday;
	}
	
	public String getEstadoCivil() {
		return estado_civil;
	}
	
	public void setEstadoCivil(String newEstadoCivil) {
		estado_civil = newEstadoCivil;
	}
	
	public void printar_pessoa() {
		System.out.printf("\nNome: %s\n", this.getNome());
		System.out.printf("Email: %s\n", this.getEmail());
		System.out.printf("Endereco: %s\n", this.getEndereco());
		System.out.printf("CPF: %s\n", this.getCpf());
		System.out.printf("Data de aniversario: %s\n", this.getDataNascimento());
		System.out.printf("Estado civil: %s\n", this.getEstadoCivil());
	}
}
