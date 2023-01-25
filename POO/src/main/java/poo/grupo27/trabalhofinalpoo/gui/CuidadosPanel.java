package poo.grupo27.trabalhofinalpoo.gui;

import java.util.ArrayList;

/**
 * Classe responsavel pelo Card sobre os cuidados com relação a COVID-19
 */
public class CuidadosPanel extends javax.swing.JPanel {
    
    /**
     * Cria o Painel de Cuidados
     * @param cuidados Uma ArrayList com todos os cuidados que devem ser adicionados no Painel
     */
    public CuidadosPanel( ArrayList<String> cuidados) {
        initComponents();
        fillInfo(cuidados);
    }
    
    /**
     * Inicia todos os componentes visuais
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        separador = new javax.swing.JSplitPane();
        painelEsquerdo = new javax.swing.JPanel();
        lblEsquerda = new javax.swing.JLabel();
        painelDireito = new javax.swing.JPanel();
        lblDireita = new javax.swing.JLabel();

        separador.setDividerLocation(960);
        separador.setDividerSize(1);

        lblEsquerda.setVerticalAlignment(javax.swing.SwingConstants.TOP);

        javax.swing.GroupLayout painelEsquerdoLayout = new javax.swing.GroupLayout(painelEsquerdo);
        painelEsquerdo.setLayout(painelEsquerdoLayout);
        painelEsquerdoLayout.setHorizontalGroup(
            painelEsquerdoLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(painelEsquerdoLayout.createSequentialGroup()
                .addContainerGap()
                .addComponent(lblEsquerda, javax.swing.GroupLayout.DEFAULT_SIZE, 195, Short.MAX_VALUE)
                .addContainerGap())
        );
        painelEsquerdoLayout.setVerticalGroup(
            painelEsquerdoLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(painelEsquerdoLayout.createSequentialGroup()
                .addContainerGap()
                .addComponent(lblEsquerda, javax.swing.GroupLayout.DEFAULT_SIZE, 288, Short.MAX_VALUE)
                .addContainerGap())
        );

        separador.setLeftComponent(painelEsquerdo);

        lblDireita.setVerticalAlignment(javax.swing.SwingConstants.TOP);

        javax.swing.GroupLayout painelDireitoLayout = new javax.swing.GroupLayout(painelDireito);
        painelDireito.setLayout(painelDireitoLayout);
        painelDireitoLayout.setHorizontalGroup(
            painelDireitoLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(painelDireitoLayout.createSequentialGroup()
                .addComponent(lblDireita, javax.swing.GroupLayout.DEFAULT_SIZE, 206, Short.MAX_VALUE)
                .addContainerGap())
        );
        painelDireitoLayout.setVerticalGroup(
            painelDireitoLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(painelDireitoLayout.createSequentialGroup()
                .addContainerGap()
                .addComponent(lblDireita, javax.swing.GroupLayout.DEFAULT_SIZE, 288, Short.MAX_VALUE)
                .addContainerGap())
        );

        separador.setRightComponent(painelDireito);

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(this);
        this.setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(separador)
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(separador)
        );
    }// </editor-fold>//GEN-END:initComponents
    
    /**
     * Preenche as Labels com as informações passadas no contrutor
     * @param cuidados 
     */
    private void fillInfo(ArrayList<String> cuidados){
        //Inicializa ambas como HTML para conseguir pular linhas
        lblEsquerda.setText("<html>");
        lblDireita.setText("<html>");
        for(int i = 0; i < cuidados.size(); i++){
            //Adiciona os Textos nas Labels
            lblEsquerda.setText(lblEsquerda.getText() + "<br/><br/>" + cuidados.get(i));
            if(cuidados.size()>++i)//Verifica se ainda existe o segundo elemento
                lblDireita.setText(lblDireita.getText() + "<br/><br/>" + cuidados.get(i));
        }
        //Finaliza o HTML
        lblEsquerda.setText(lblEsquerda.getText() + "</html>");
        lblDireita.setText(lblDireita.getText() + "</html>");
    }
    

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JLabel lblDireita;
    private javax.swing.JLabel lblEsquerda;
    private javax.swing.JPanel painelDireito;
    private javax.swing.JPanel painelEsquerdo;
    private javax.swing.JSplitPane separador;
    // End of variables declaration//GEN-END:variables
}
