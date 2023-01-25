/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package poo.grupo27.trabalhofinalpoo.gui;

import java.awt.CardLayout;
import java.util.ArrayList;
import javax.swing.JPanel;
import poo.grupo27.trabalhofinalpoo.gerenciadorGui.Cards;
import poo.grupo27.trabalhofinalpoo.gerenciadorGui.PanelController;

/**
 * Frame responsavel pela parte principal do programa
 */
public class MainFrame extends javax.swing.JFrame {
    private CardLayout cl;
    private PanelController controller;
    /**
     * Cria o Frame principal
     * @param controller é a classe de gerencia do programa
     */
    public MainFrame(PanelController controller) {
        initComponents();
        this.controller = controller;
    }
    
    /**
     * Define qual será o próximo Card a ser mostrado
     * @param nextFrame proximo card
     */
    public void setFrame(Cards nextFrame){
        cl.show(panelMain, nextFrame.getValue());
    }
    
    /**
     * Adiciona uma lista de cards ao frame
     * @param list Lista de Cards
     * @param nomes Nomes dos Cards
     */
    public void putFrames(ArrayList<JPanel> list, ArrayList<String> nomes){
        for (int i = 0; i < list.size(); i++) {
            panelMain.add(list.get(i),nomes.get(i));
        }
    }
    
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        panelHeader = new javax.swing.JPanel();
        jButton1 = new javax.swing.JButton();
        panelMain = new javax.swing.JPanel();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        setTitle("Projeto Final POO");
        setPreferredSize(new java.awt.Dimension(1920, 800));

        panelHeader.setBackground(new java.awt.Color(204, 0, 51));

        jButton1.setText("Home");
        jButton1.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton1ActionPerformed(evt);
            }
        });

        javax.swing.GroupLayout panelHeaderLayout = new javax.swing.GroupLayout(panelHeader);
        panelHeader.setLayout(panelHeaderLayout);
        panelHeaderLayout.setHorizontalGroup(
            panelHeaderLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(panelHeaderLayout.createSequentialGroup()
                .addComponent(jButton1, javax.swing.GroupLayout.PREFERRED_SIZE, 78, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(0, 1318, Short.MAX_VALUE))
        );
        panelHeaderLayout.setVerticalGroup(
            panelHeaderLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(jButton1, javax.swing.GroupLayout.DEFAULT_SIZE, 40, Short.MAX_VALUE)
        );

        panelMain.setLayout(new java.awt.CardLayout());

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(panelHeader, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
            .addComponent(panelMain, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addComponent(panelHeader, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(panelMain, javax.swing.GroupLayout.DEFAULT_SIZE, 819, Short.MAX_VALUE))
        );

        cl = (CardLayout) (panelMain.getLayout());

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void jButton1ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButton1ActionPerformed
        controller.changeActualFrame(Cards.MAIN_FRAME);
    }//GEN-LAST:event_jButton1ActionPerformed
    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton jButton1;
    private javax.swing.JPanel panelHeader;
    private javax.swing.JPanel panelMain;
    // End of variables declaration//GEN-END:variables
}
