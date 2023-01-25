package poo.grupo27.trabalhofinalpoo.gui;

import poo.grupo27.trabalhofinalpoo.gerenciadorGui.Cards;
import poo.grupo27.trabalhofinalpoo.gerenciadorGui.PanelController;
import poo.grupo27.trabalhofinalpoo.gerenciadorGui.State;

/**
 * Classe responsavel pelo Card menu principal
 */
public class HomePanel extends javax.swing.JPanel {
    
    PanelController controller;
    
    /**
     * Cria o painel principal
     * @param controller é a classe de gerencia do programa
     */
    public HomePanel(PanelController controller) {
        this.controller = controller;
        initComponents();
    }

    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        lblWelcome = new javax.swing.JLabel();
        lblEstado = new javax.swing.JLabel();
        comboBoxEstados = new javax.swing.JComboBox<>();
        lblAction = new javax.swing.JLabel();
        btnConsultaVacina = new javax.swing.JButton();
        btnGrafico = new javax.swing.JButton();
        btnInfos = new javax.swing.JButton();
        btnCuidados = new javax.swing.JButton();
        btnFAQ = new javax.swing.JButton();

        lblWelcome.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        lblWelcome.setText("Bem vindo ao centro de informações da COVID-19");

        lblEstado.setHorizontalAlignment(javax.swing.SwingConstants.TRAILING);
        lblEstado.setText("Selecione seu estado:");

        comboBoxEstados.setModel(new javax.swing.DefaultComboBoxModel<>(State.getAllNames()));

        lblAction.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        lblAction.setText("O que deseja fazer?");

        btnConsultaVacina.setText("Consultar quando serei vacinado");
        btnConsultaVacina.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnConsultaVacinaActionPerformed(evt);
            }
        });

        btnGrafico.setText("Consultar gráficos do estado");
        btnGrafico.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnGraficoActionPerformed(evt);
            }
        });

        btnInfos.setText("Informações sobre vacinas");
        btnInfos.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnInfosActionPerformed(evt);
            }
        });

        btnCuidados.setText("Cuidados gerais");
        btnCuidados.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnCuidadosActionPerformed(evt);
            }
        });

        btnFAQ.setText("Fui vacinado, e agora?");
        btnFAQ.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnFAQActionPerformed(evt);
            }
        });

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(this);
        this.setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(lblWelcome, javax.swing.GroupLayout.Alignment.TRAILING, javax.swing.GroupLayout.DEFAULT_SIZE, 300, Short.MAX_VALUE)
            .addGroup(layout.createSequentialGroup()
                .addContainerGap()
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, layout.createSequentialGroup()
                        .addComponent(lblEstado)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(comboBoxEstados, 0, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
                    .addComponent(lblAction, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addComponent(btnConsultaVacina, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addComponent(btnGrafico, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addComponent(btnInfos, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addComponent(btnCuidados, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addComponent(btnFAQ, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
                .addContainerGap())
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addContainerGap()
                .addComponent(lblWelcome)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(lblEstado)
                    .addComponent(comboBoxEstados, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(lblAction)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(btnConsultaVacina)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(btnGrafico)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(btnInfos)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(btnCuidados)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(btnFAQ)
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
        );
    }// </editor-fold>//GEN-END:initComponents

    //Os métodos executados em cada botão
    private void btnConsultaVacinaActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnConsultaVacinaActionPerformed
        controller.changeActualFrame(Cards.DATE_FRAME);
    }//GEN-LAST:event_btnConsultaVacinaActionPerformed

    private void btnGraficoActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnGraficoActionPerformed
        controller.changeActualFrame(Cards.GRAPH_FRAME);
    }//GEN-LAST:event_btnGraficoActionPerformed

    private void btnInfosActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnInfosActionPerformed
        controller.changeActualFrame(Cards.INFO_FRAME);
    }//GEN-LAST:event_btnInfosActionPerformed

    private void btnCuidadosActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnCuidadosActionPerformed
        controller.changeActualFrame(Cards.CARE_FRAME);
    }//GEN-LAST:event_btnCuidadosActionPerformed

    private void btnFAQActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnFAQActionPerformed
        controller.changeActualFrame(Cards.FAQ_FRAME);
    }//GEN-LAST:event_btnFAQActionPerformed


    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton btnConsultaVacina;
    private javax.swing.JButton btnCuidados;
    private javax.swing.JButton btnFAQ;
    private javax.swing.JButton btnGrafico;
    private javax.swing.JButton btnInfos;
    private javax.swing.JComboBox<String> comboBoxEstados;
    private javax.swing.JLabel lblAction;
    private javax.swing.JLabel lblEstado;
    private javax.swing.JLabel lblWelcome;
    // End of variables declaration//GEN-END:variables
}
