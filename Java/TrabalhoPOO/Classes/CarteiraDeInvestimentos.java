package classes;

import java.util.ArrayList;
//import java.util.Collection;
import java.util.List;


public class CarteiraDeInvestimentos  {
	
	//Usando a API Collection em vez de ARRAYS 
	//AplicacoesPrimarias[] AplicacoesPrimarias;
	List<Aplicacoes> aplicacaoPrimaria ;
	
	public CarteiraDeInvestimentos() {
		this.aplicacaoPrimaria = new ArrayList<>();
	}
	
	public void addAplicacao(Aplicacoes a) {
		aplicacaoPrimaria.add(a);
	}
	
	public double getEstimativaDeRisco() {
		double risco = 0;
		for(int i = 0; i < aplicacaoPrimaria.size(); i++) {
			Aplicacoes ap = aplicacaoPrimaria.get(i); // sem casting!
			risco += ap.getEstimativaDeRisco() * ap.getFatia();
		}
		return risco/100;
	}
	public double getEstimativaDeRendimento() {
		double rendimento = 0;
		for(int i = 0; i < aplicacaoPrimaria.size(); i++) {
			Aplicacoes ap = aplicacaoPrimaria.get(i); // sem casting!
			rendimento += ap.getEstimativaDeRendimento() * ap.getFatia();
		}
		
		return rendimento/100;
		
	}
	
	//COM ARRAY EM VEZ DA COLLECTION
	
	/*
	public float getEstimativaDeRisco() {
		float risco=0;
		for(int i=0;i<AplicacoesPrimarias.length;i++)
			risco+=AplicacoesPrimarias[i].getEstimativaDeRisco() * AplicacoesPrimarias[i].getFatia();
				
		return risco/100;
	}
	
	public float getEstimativaDeRendimento(){
		float rendimento=0;
		for(int i=0;i<AplicacoesPrimarias.length;i++)
			rendimento+=AplicacoesPrimarias[i].getEstimativaDeRendimento() * AplicacoesPrimarias[i].getFatia();
		
		return rendimento/100;
	}
	*/
	public void valores() {
			for(int i = 0; i < aplicacaoPrimaria.size(); i++) {
				Aplicacoes ap = aplicacaoPrimaria.get(i);
				System.out.println(" " + ap.getDescricao()  +  ap.getCodigo()  + ap.getEstimativaDeRisco() + ap.getEstimativaDeRendimento() + ap.getFatia());
			}	
	}
}
