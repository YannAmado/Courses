/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package poo.grupo27.trabalhofinalpoo.gui.auxiliar;

import java.awt.Dimension;

/**
 * Representa um botão com uma label integrada
 */
public class ButtonExpansible extends javax.swing.JPanel {

    
    private final String labelText;
    /**
     * Cria um botão que quando clicado cria uma label com um texto interno
     * @param btnText Texto do Botao
     * @param labelText Texto da Label
     */
    public ButtonExpansible(String btnText, String labelText) {
        this.labelText = labelText;
        initComponents();
        defineBotao(btnText);
    }
    
    /**
     * Define algumas constantes no Botão
     * @param btnText Texto a ser inserido
     */
    private void defineBotao(String btnText){
        this.setPreferredSize(new Dimension(btnText.length()*40,40));
        btn.setText(btnText);
        btn.addActionListener((java.awt.event.ActionEvent evt) -> {
            lbl.setText(labelText);
        });
    }

    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        btn = new javax.swing.JButton();
        lbl = new javax.swing.JLabel();

        setLayout(new java.awt.BorderLayout());

        btn.setText("");
        btn.setHorizontalAlignment(javax.swing.SwingConstants.LEFT);
        add(btn, java.awt.BorderLayout.CENTER);
        add(lbl, java.awt.BorderLayout.PAGE_END);
    }// </editor-fold>//GEN-END:initComponents


    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton btn;
    private javax.swing.JLabel lbl;
    // End of variables declaration//GEN-END:variables
}
