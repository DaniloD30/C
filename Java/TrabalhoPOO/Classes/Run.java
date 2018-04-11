package classes;

public class Run {
	
	public static void main(String[] args) {
		//instanciando uma carteira 
		 CarteiraDeInvestimentos carteira = new CarteiraDeInvestimentos();
		//criando uma aplicação
		 AplicacoesPrimarias p = new AplicacoesPrimarias("CDB","Certificado de Depósito Bancário",0.153,0.63,15,1000.00);
		 AplicacoesPrimarias l = new AplicacoesPrimarias("PETR4","Ações da Petrobrás",0.487,0.9,20,300.00);
		 AplicacoesPrimarias c = new AplicacoesPrimarias("BBSE3","BB Seguridade",0.357,0.98f,40f,100.00);
		 AplicacoesPrimarias d = new AplicacoesPrimarias("POUP","Poupança",0.001,0.05,15,700.00);
		 AplicacoesPrimarias e = new AplicacoesPrimarias("VALE5","Vale",0.698,1.7,10,900.00);
		 //INSERINDO UMA APLICACAO EM UMA CARTEIRA
		 carteira.addAplicacao(p);
		 carteira.addAplicacao(l);
		 carteira.addAplicacao(c);
		 carteira.addAplicacao(d);
		 carteira.addAplicacao(e);
		 System.out.println(" " + carteira.getEstimativaDeRisco());
		 System.out.println(" " + carteira.getEstimativaDeRendimento());
		 
		 
		 
		

		 
	
	}
}
