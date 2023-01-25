package poo.grupo27.trabalhofinalpoo.gerenciadorGui;

/**
 * Representa todos os estados do Brasil
 */

public enum State {
    AC("Acre","AC",0),AL("Alagoas","AL",1),AP("Amapá","AP",2),
    AM("Amazonas","AM",3),BA("Bahia","BA",4),CE("Ceará","CE",5),
    DF("Distrito Federal","DF",6),ES("Espírito Santo","ES",7),
    GO("Goiás","GO",8),MA("Maranhão","MA",9),MT("Mato Grosso","MT",10),
    MS("Mato Grosso do Sul","MS",11),MG("Minas Gerais","MG",12),
    PA("Pará","PA",13),PB("Paraíba","PB",14),PR("Paraná","PR",15),
    PE("Pernambuco","PE",16),PI("Piauí","PI",17),RJ("Rio de Janeiro","RJ",18),
    RN("Rio Grande do Norte","RN",19),RS("Rio Grande do Sul","RS",20),
    RO("Rondônia","RO",21),RR("Roraima","RR",22),SC("Santa Catarina","SC",23),
    SP("São Paulo","SP",24),SE("Sergipe","SE",25),TO("Tocantins","TO",26);
    private final String name, sigla;
    private final int id;
    private State(String name, String sigla,int id){
        this.name = name;
        this.sigla = sigla;
        this.id = id;
    }
    public String getName(){
        return name;
    }
    
    public String getSigla(){
        return sigla;
    }
    
    public int getId(){
        return id;
    }

    @Override
    public String toString() {
        return name + "(" + sigla + ")";
    }
    /**
     * @return retorna todos os nomes dos estados
     */
    public static String[] getAllNames(){
        State[] states = State.values();
        String[] names = new String[states.length];
        for (int i = 0; i < states.length; i++) {
            names[i] = states[i].toString();
        }
        return names;
    }
    
}
