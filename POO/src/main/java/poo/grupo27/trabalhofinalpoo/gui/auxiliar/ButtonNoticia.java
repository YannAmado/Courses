package poo.grupo27.trabalhofinalpoo.gui.auxiliar;

import java.awt.event.ActionEvent;
import javax.swing.JFrame;

/**
 * Classe usada para criar um botão de noticias
 */
public class ButtonNoticia extends javax.swing.JPanel {

    /**
     * Cria o botão para uma noticia
     * @param title Titulo da noticia
     * @param body Corpo da noticia
     */
    public ButtonNoticia(String title, String body ) {
        initComponents();
        btn.setText(quebraString(body, 50));
        btn.addActionListener((ActionEvent avt) -> {
            FrameNoticia temp = new FrameNoticia(quebraString(title, 200));
            temp.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
            temp.setVisible(true);
        });
    }
    
    private String quebraString(String in, int size){
        String out = "<html>";
        int i = 1;
        for(; i < in.length(); i++){
            if(i%size == 0){
                out += in.substring(i-size, size);
                if(in.charAt(i) > 32)
                    out += "-";
                out += "<br>";
            }
        }
        out += in.substring(Math.floorDiv(i, size));
        out += "</html>";
        return out;
    }

    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        btn = new javax.swing.JButton();

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(this);
        this.setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(btn, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(btn, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
        );
    }// </editor-fold>//GEN-END:initComponents


    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton btn;
    // End of variables declaration//GEN-END:variables
}
