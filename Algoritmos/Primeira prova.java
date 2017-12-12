/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package provai;

/**
 *
 * @author Aluno
 */
public class ProvaI {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        Gene g = new Gene();
        Gene g1 = new Gene();
        Gene novogene = new Gene();
        //Gene novo = new Gene();
        //Gene i = new Gene();
        
        g.alterar(10);
        g1.alterar(20);
        System.out.println("Iguais?: "+ g.equals(g1));
        
        novogene = g.clonar();
        System.out.println("valor: "+ novogene.ler());
        
    }
    
}

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package provai;

/**
 *
 * @author Aluno
 */
public class Gene {
    private int estado;
    
    
    public Gene(int estado){
        this.setEstado(estado);
    }
    public boolean equals(Gene outro){
        return (this.getEstado() == outro.getEstado());
     }
    public Gene clonar(){
        Gene clone = new Gene(0);
        clone.setEstado(this.getEstado());
        return clone;
    }
    
    //METODOS ACESSORES

    private int getEstado() {
        return estado;
    }
    
    private void setEstado(int estado) {
        this.estado = estado;
    }
    
    
    
}

_____ CLASSE 2 ___________

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package prova.i.pkg2017.pkg1;

/**
 *
 * @author Aluno
 */
public class Cromossomo {
    private int numeroGene;
    private int numeroQueRecebeCromo;
    
    public Cromossomo(int numeroGene){
        this.setNumeroGene(numeroGene);
        Cromossomo vet[] = new Cromossomo[numeroGene];
    }
    public int buscar(int alelo){
        if(vet[alelo] != null){
            return 
        }
    }
    
    private int getNumeroGene() {
        return numeroGene;
    }

    private void setNumeroGene(int numeroGene) {
        this.numeroGene = numeroGene;
    }
    
    
}

