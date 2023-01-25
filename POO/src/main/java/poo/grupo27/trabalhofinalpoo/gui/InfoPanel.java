package poo.grupo27.trabalhofinalpoo.gui;

import java.util.ArrayList;
import javax.swing.JPanel;
import poo.grupo27.trabalhofinalpoo.gui.auxiliar.ButtonNoticia;

/**
 * Classe responsavel pelo Card de informações
 */
public class InfoPanel extends javax.swing.JPanel {
    
    /**
     * Cria o painel de informações
     * @param noticias Corpo das noticias
     * @param titulos Titulo das noticias
     */
    public InfoPanel(ArrayList<String> noticias,ArrayList<String> titulos) {
        initComponents();
        populaNoticias(titulos, noticias);
    }
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        lblHeader = new javax.swing.JLabel();
        panelBtnNoticias = new javax.swing.JPanel();

        setLayout(new org.netbeans.lib.awtextra.AbsoluteLayout());

        lblHeader.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        lblHeader.setText("Noticias sobre:");
        add(lblHeader, new org.netbeans.lib.awtextra.AbsoluteConstraints(0, 0, -1, -1));

        panelBtnNoticias.setLayout(new javax.swing.BoxLayout(panelBtnNoticias, javax.swing.BoxLayout.PAGE_AXIS));
        add(panelBtnNoticias, new org.netbeans.lib.awtextra.AbsoluteConstraints(0, 20, 1920, 600));
    }// </editor-fold>//GEN-END:initComponents

    /**
     * Insere no Card as noticias
     * @param titulos titulos das noticias
     * @param noticias corpo das noticias
     */
    public void populaNoticias(ArrayList<String> titulos, ArrayList<String> noticias){
        panelBtnNoticias = new JPanel();
        panelBtnNoticias.setLayout(new javax.swing.BoxLayout(panelBtnNoticias, javax.swing.BoxLayout.PAGE_AXIS));
        for(int i = 0; i < noticias.size(); i++){
            panelBtnNoticias.add(new ButtonNoticia(titulos.get(i),noticias.get(i)));
        }
        remove(panelBtnNoticias);
        add(panelBtnNoticias, new org.netbeans.lib.awtextra.AbsoluteConstraints(0, 20, 1920, 600));
        this.validate();
    }
    
    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JLabel lblHeader;
    private javax.swing.JPanel panelBtnNoticias;
    // End of variables declaration//GEN-END:variables
}


/*JLabel temp;
for(int i = 0; i < noticias.size(); i++){
    add(temp = new JLabel(noticias.get(i)));
    temp.setHorizontalAlignment(javax.swing.SwingConstants.LEFT);
}
*/