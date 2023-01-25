package poo.grupo27.trabalhofinalpoo.gerenciadorGui;

import external.Database;
import external.Estado;
import java.util.ArrayList;
import java.util.Arrays;
import javax.swing.JPanel;
import poo.grupo27.trabalhofinalpoo.gui.*;

/**
 * Serve para controlar os cards do MainFrame
 */
public class PanelController {
    private State estado;
    private final MainFrame main;
    private final HomePanel home;
    private final DataVacinaPanel data;
    private final InfoPanel info;
    private final CuidadosPanel cuidados;
    private final FAQPanel faq;
    private final GraficosPanel graph;
    private final Database database;
    
    public PanelController(String []comoborbidades, String []cuidados, String []perguntas, String []respostas, Database db, Estado []estados){
        //Cria todos os frames que são usados no programa
        database = db;
        main = new MainFrame(this);
        home = new HomePanel(this);
        data = new DataVacinaPanel(new ArrayList<>(Arrays.asList(comoborbidades)));
        String []header = new String[2];
        header[0] = "Vacinas";
        header[1] = "Média Movel";
        info = new InfoPanel(new ArrayList<>(Arrays.asList(header)),new ArrayList<>(Arrays.asList(database.getNews(0))));
        this.cuidados = new CuidadosPanel(new ArrayList<>(Arrays.asList(cuidados)));
        graph = new GraficosPanel(this, estados);
        faq = new FAQPanel( new ArrayList<>(Arrays.asList(perguntas)),  new ArrayList<>(Arrays.asList(respostas)));
        //Adiciona todos em uma ArrayList
        ArrayList<JPanel> array = new ArrayList();
        array.add(home);
        array.add(data);
        array.add(info);
        array.add(this.cuidados);
        array.add(graph);
        array.add(faq);
        //Coloca tudo em um vetor de referencia para a troca dos Cards
        String names[] = {Cards.MAIN_FRAME.getValue(), Cards.DATE_FRAME.getValue(), Cards.INFO_FRAME.getValue(), Cards.CARE_FRAME.getValue(),Cards.GRAPH_FRAME.getValue() ,Cards.FAQ_FRAME.getValue()};
        //Adiciona os cards no MainFrame
        main.putFrames(array, new ArrayList<>(Arrays.asList(names)));
        //Coloca a Home como primeira a ser exibida
        main.setFrame(Cards.MAIN_FRAME);
        //Inicia o visual
        main.setVisible(true);
        
        estado = State.AC;
    }
    
    /**
     * Muda o estado que esta sendo consideirado
     * @param newState novo estado
     */
    public void changeState(State newState){
        estado = newState;
        String []header = new String[2];
        header[0] = "Vacinas";
        header[1] = "Média Movel";
        info.populaNoticias(new ArrayList<>(Arrays.asList(header)),new ArrayList<>(Arrays.asList(database.getNews(newState.getId()))));
        
    }
    
    public State getState(){
        return estado;
    }
    
    /**
     * Muda o frame que está sendo exibido
     * @param nextFrame Indica qual será o proximo a ser mostrado
     */
    public void changeActualFrame(Cards nextFrame){
        main.setFrame(nextFrame);
    }
}