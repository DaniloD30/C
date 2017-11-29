package lampada;

/**
 *
 * @author aluno
 */
public class Lampada {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
      Modulo mod = new Modulo();
      
      
      mod.acenderCount();
      mod.apagarCount();
      mod.acenderCount();
      
        System.out.println("Quantidade: " + mod.quant());
        System.out.println("Esta acesa? "+ mod.status());
        
        
        
        
        
        
         
         
        
        
    }
}


/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package lampada;

/**
 *
 * @author aluno
 */
public class lamp {
        private boolean situacao;

    public lamp(boolean situacao) {
        this.situacao = false;
    }
        
        
        public void acender(){
            this.setSituacao(true);
        }
        public void apagar(){
            this.setSituacao(false);
        }
        public boolean status(){
            return this.isSituacao();
            
        }

    private boolean isSituacao() {
        return situacao;
    }

    private void setSituacao(boolean situacao) {
        this.situacao = situacao;
    }
        
}

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package lampada;

/**
 *
 * @author aluno
 */
public class contador {
    private int count;

    public contador() {
        this.count = 0;
    }
    
    
    public void incrementar(){
        this.setCount(this.getCount() + 1);
    }
    public void zerar(){
        this.setCount(0);
        
    }
    public int quantidade(){
        return getCount();
    }

    private int getCount(){
        return count;
    }

    private void setCount(int count){
        this.count = count;
    }
    
    
    
}


package lampada;

/**
 *
 * @author aluno
 */
public class Modulo {
    lamp l = new lamp();
    contador count = new contador();
    
    public void acenderCount(){
        if(!l.status()){
            l.acender();
            count.incrementar();
        }
    }
    public void apagarCount(){
        if(l.status()){
            l.apagar();
            count.incrementar();
        }
    }
    public int quant(){
        return count.quantidade();
    }
   public boolean status(){
       return l.status();
   }
    
}
