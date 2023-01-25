    package external;

public class Estado {
	public int dias;
	public int id;
	public int[] infectados;
	public int[] recuperados;
	public int[] mortos;
	public int[] vacinados;
	public int[] diaVacinacao;
	public String[] noticias;
	Database database;

	public Estado(int id) {
                database = new Database();
		this.dias = database.getDias();
		this.infectados = database.getInfectados(id, this.dias);
		this.recuperados = database.getRecuperados(id, this.dias);
		this.mortos = database.getMortos(id, this.dias);
		this.vacinados = database.getVacinados(id, this.dias);
		this.noticias = database.getNews(id);
		this.diaVacinacao = database.getDataVacina(id);
	}

	public void plot_infectados() {
		String title = "Número de Infectados";
		String legenda = "Gráfico referente à progressão do número de infectados nos últimos" + String.valueOf(this.dias);

		Plot.plotChart(title, legenda, this.infectados);
	}

	public void plot_recuperados() {
		String title = "Número de Recuperados";
		String legenda = "Gráfico referente à progressão do número de recuperados nos últimos" + String.valueOf(this.dias);

		Plot.plotChart(title, legenda, this.recuperados);
	}

	public void plot_mortos() {
		String title = "Número de Mortos";
		String legenda = "Gráfico referente à progressão do número de mortos nos últimos" + String.valueOf(this.dias);

		Plot.plotChart(title, legenda, this.mortos);
	}

	public void plot_vacinados() {
		String title = "Número de Vacinados";
		String legenda = "Gráfico referente à progressão do número de vacinados nos últimos" + String.valueOf(this.dias);

		Plot.plotChart(title, legenda, this.vacinados);
	}

	public void print_noticias() {
		for(int i = 0; i < this.noticias.length; i++)
			System.out.println(i + ")" + this.noticias[i] + "\n");
	}

	public void print_data(int grupo){
		System.out.println("Uma vez no grupo " + grupo + " vocẽ pode se vacinar dia " + this.diaVacinacao[grupo - 1]);
	}
}