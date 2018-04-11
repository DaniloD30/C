package classes;

public class BancoInvestimentos {
	
	public static void main(String[] args) {
		//instanciando uma carteira 
		 CarteiraDeInvestimentos carteira = new CarteiraDeInvestimentos();
		//criando uma aplicação
		 AplicacoesPrimarias p = new AplicacoesPrimarias("CDB","Certificado de Depósito Bancário",0.153f,0.63f,15f,1000.00f);
		 
		 //INSERINDO UMA APLICACAO EM UMA CARTEIRA
		 carteira.addAplicacao(p);
		 
		 
		 
	
	}
}
