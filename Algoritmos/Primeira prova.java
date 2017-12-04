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
    
    public void alterar(int estado){
        this.setEstado(estado);
    }
    public int ler(){
        return this.getEstado();
    }
    
    private int getEstado(){
        return estado;
    }

    private void setEstado(int estado) {
        this.estado = estado;
    }
       public boolean equals(Gene g){
        return (this.getEstado() == g.ler());
     }
    public Gene clonar(){
        Gene n = new Gene();
        n.alterar(this.ler());
       
        return n;
    }
    
    
}
