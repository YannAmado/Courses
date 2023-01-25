package poo.grupo27.trabalhofinalpoo.gerenciadorGui;

/**
 * Enum que representa todos os possiveis Cards que o programa tem na pagina principal (Não entram na conta o FrameNoticia já que o mesmo é aberto em uma nova janela)
 */
public enum Cards{
    MAIN_FRAME("Main"),GRAPH_FRAME("Graph"),DATE_FRAME("Date"),FAQ_FRAME("FAQ"),CARE_FRAME("Care"),INFO_FRAME("Info");
    private final String valorCard;
    private Cards(String valor) {
        valorCard = valor;
    }
    //Retorna o valor atual do Frame
    public String getValue(){
        return valorCard;
    }
}
