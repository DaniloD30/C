/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package lampada;

import java.util.Scanner;

/**
 *
 * @author aluno
 */
public class Lampada {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        Scanner scanner = new Scanner(System.in);  
        System.out.println ("Insira o numero");
        int i = scanner.nextInt();
        System.out.println ("Insira o numero");
        int j = scanner.nextInt();
        l lamp = new l();
        l lamp2 = new l();
        
        lamp.acender();
        lamp2.acender();
        
        if(i == 1)
            lamp.apagar();
        else
            lamp2.apagar();
        
        if(j == 1)
            System.out.println("Lampada 1: "+ lamp.isStatus());
        else
            System.out.println("Lampada 2: "+ lamp2.isStatus());
        
        System.out.println("Contador: "+ lamp.getCount());
        System.out.println("Contador "+ lamp2.getCount());
        
        
        
        
        
        
        
         
         
        
        
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
public class l {
    public boolean status;
    public int count;

    public l() {
        this.status = false;
    }
    public void acender(){
        this.setStatus(true);
        this.setCount(this.getCount() + 1);
    }
    public void apagar(){
        this.setStatus(false);
        this.setCount(this.getCount() + 1);
    }
    public boolean isStatus() {
        return status;
    }
    public void setStatus(boolean status) {
        this.status = status;
    }

    public int getCount() {
        return count;
    }

    public void setCount(int count) {
        this.count = count;
    }
    
}
