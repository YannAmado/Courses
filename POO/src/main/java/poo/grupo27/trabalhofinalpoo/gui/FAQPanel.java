package poo.grupo27.trabalhofinalpoo.gui;

import java.util.ArrayList;
import poo.grupo27.trabalhofinalpoo.gui.auxiliar.ButtonExpansible;

/**
 * Classe responsavel pelo Card de perguntas frequentes
 */
public class FAQPanel extends javax.swing.JPanel {
    
    /**
     * Cria o painel de perguntas frequentes
     * @param perguntas Uma ArrayList<String> com todas as perguntas frequentes
     * @param respostas Uma ArrayList<String> com todas as respostas das perguntas
     */
    public FAQPanel( ArrayList<String> perguntas, ArrayList<String> respostas) {
        initComponents();
        populaBtn(perguntas, respostas);
    }
    
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        setPreferredSize(new java.awt.Dimension(300, 420));
        setLayout(new javax.swing.BoxLayout(this, javax.swing.BoxLayout.PAGE_AXIS));
    }// </editor-fold>//GEN-END:initComponents
    /**
     * Insere os botões expansiveis no Painel
     * @param perguntas Uma ArrayList<String> com todas as perguntas frequentes
     * @param respostas Uma ArrayList<String> com todas as respostas das perguntas
     */
    private void populaBtn(ArrayList<String> perguntas, ArrayList<String> respostas){
        for(int i = 0; i < perguntas.size(); i++){
            add(new ButtonExpansible(perguntas.get(i),respostas.get(i)));
        }
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    // End of variables declaration//GEN-END:variables
}
