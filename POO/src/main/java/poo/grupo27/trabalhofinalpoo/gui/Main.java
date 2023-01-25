/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package poo.grupo27.trabalhofinalpoo.gui;

import external.Database;
import external.Estado;
import poo.grupo27.trabalhofinalpoo.gerenciadorGui.PanelController;

/**
 *
 * @author edupo
 */
public class Main {
    public static void main(String[] args){
        String []comorbidades, cuidados, perguntas, respostas;
        comorbidades = new String[9];
        comorbidades[0] = "Indigenas ou comunidades tradicionais";
        comorbidades[1] = "Trabalhadores da saude";
        comorbidades[2] = "Portadores de alguma deficiência institucionalizadas";
        comorbidades[3] = "Gestantes";
        comorbidades[4] = "Moradores de rua";
        comorbidades[5] = "Profissionais das forças armadas";
        comorbidades[6] = "Portadores de comorbidade";
        comorbidades[7] = "Profissionais da educação";
        comorbidades[8] = "Profissionais da área de transportes";
        cuidados = new String[14];
        cuidados[0] = "Não esqueça de lavar bem as mãos"; 
        cuidados[1] = "Use álcool em gel"; 
        cuidados[2] = "Não compartilhe sua máscara com outras pessoas"; 
        cuidados[3] = "Evite tocar em seus olhos, nariz e boca"; 
        cuidados[4] = "Mantanha-se sempre em locais ventilados"; 
        cuidados[5] = "Se sair de casa, use máscara"; 
        cuidados[6] = "Mantenha o distanciamento social de pelo menos 1 metro"; 
        cuidados[7] = "Evite aglomerações"; 
        cuidados[8] = "Ao sentir algum sintoma, procure o médico"; 
        cuidados[9] = "Se for possível, se vacine no posto mais próximo"; 
        cuidados[10] = "Fique em casa caso sinta-se indisposto(a)"; 
        cuidados[11] = "Pesquise informações apenas em fontes confiáveis"; 
        cuidados[12] = "Em caso de suspeita, faça o teste após 4 dias da aparição dos sintomas"; 
        cuidados[13] = "Em caso de infecção, isole-se por ao menos 2 semanas"; 
        perguntas = new String[6];
        perguntas[0] = "Fui vacionado, não preciso mais usar máscara?";
        perguntas[1] = "Já peguei covid, preciso me vacinar?";
        perguntas[2] = "A 2ª dose é necessária?";
        perguntas[3] = "Não estou no grupo de risco. Estou seguro?";
        perguntas[4] = "Qual vacina é melhor?";
        perguntas[5] = "O que preciso para me vacinar?";
        respostas = new String[6];
        respostas[0] = "Sim você precisa! A vacina evita o contágio, mas não a transmissão, portanto ao usar a máscara você continua protegendo você e as pessoas a seu redor";
        respostas[1] = "Sim! Mesmo que já tenha contagiado a doença, nada impede uma reinfecção. Portanto, se possível, vacine-se no posto mais próximo";
        respostas[2] = "Tomar 2ª dose resulta em uma maior imunidade contra as variantes do vírus. Ao tomar ambas as doses, a chance de infecção é reduzida, portanto deve-se tomar a 2ª dose";
        respostas[3] = "O vírus da COVID-19 não afeta somente as pessoas do grupo de risco, pode afetar qualquer pessoa. Portanto, ainda deve-se seguir os cuidados gerais para prevenção do contágio";
        respostas[4] = "Todas as vacinas possuem o mesmo objetivo, sua proteção. Portanto, não importa com qual vacina você pode ou não ser vacinado, o importante é ser vacinado";
        respostas[5] = "Basta comprovar que pertence à faixa etária correspondente à fase de vacinação. Então de forma geral, a apresentação de um documento de identificação como o RG é o suficiente. Alguma cidades, porém, podem seguir regulamentos mais restritos. Então também é importante pesquisar em fontes confiáveis sobre o processo de vacinação na sua cidade";
        Estado[] estado = new Estado[27];
        for(int i = 0; i <= 26; i++) {
                estado[i] = new Estado(i);
        }
        PanelController pc = new PanelController(comorbidades,cuidados,perguntas,respostas, new Database(), estado);
    }
}
