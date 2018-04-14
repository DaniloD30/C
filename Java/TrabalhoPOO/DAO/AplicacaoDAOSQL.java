package dao;

import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.Collection;
import classes.Aplicacoes;
import classes.AplicacoesPrimarias;
import classes.BancoInvestimentos;
import classes.CarteiraDeInvestimentos;

public class AplicacaoDAOSQL extends AbstractDAOSQL implements InterfaceAplicacoesDAOIF{

	
  
	
	private static final String SELECT_ALL = "SELECT codigo, descricao, rendimento, risco, tipo FROM APLICACAO";
	private static final String SELECT_ALL_CARTEIRA = "SELECT ";//inner join
	
	private CarteiraDeInvestimentos createCarteira(String codigo, String descricao, double rendimento, double risco, int tipo,double fatia, double valorMinimo) {
		CarteiraDeInvestimentos carteira = null;
		if(tipo == Aplicacoes.PRIMARIA);
			carteira = new AplicacoesPrimarias(codigo,descricao,risco,Rendimento,
					 fatia,  valorMinimo);
		else if(tipo == Conta.CARTEIRA) {
			carteira = new Carteira(codigo, descricao, rendimento, risco);
			Collection<Conta> aplicacoes = this.retrieveAplicacoes(codigo);
			carteira.setAplicacoes(aplicacoes);
		}
		return conta;
	}
	
	private Collection<Aplicacoes> retrieveAplicacoes() {
		Collection <Aplicacoes> Aplicacoes = new ArrayList<Aplicacoes>();
		PreparedStatement stmt = this.getConnection().prepareStatement(SELECT_ALL);
		ResultSet rSet = stmt.executeQuery();
		while(rSet.next()){
			String codigo = rSet.getString("codigo");
			String descricao = rSet.getString("descricao");
			double rendimento = rSet.getDouble("rendimento");
			double risco = rSet.getDouble("risco");
			int tipo = rSet.getInt("tipo");
			double fatia = rSet.getDouble("fatia");
			double valorMinimo = rSet.getDouble("valorMinimo");
			Aplicacoes Aplicacoess = this.createCarteira(codigo,descricao,risco,rendimento,
					 tipo, fatia,  valorMinimo);
			Aplicacoes.add(Aplicacoess);
		}
		return Aplicacoes;
	}
	
	private int getTipo(Aplicacoes aplicacoes) {
		if(aplicacoes.getClass() == AplicacoesPrimarias.class)
			return Aplicacoes.PRIMARIA;
		if(aplicacoes.getClass() == CarteiraDeInvestimentos.class)
			return Aplicacoes.CARTEIRA;
	
		return -1;
	}

	@Override
	public Collection<Aplicacoes> buscarTodos() throws Exception {
		Collection <Aplicacoes> Aplicacoes = new ArrayList<Aplicacoes>();
		PreparedStatement stmt = this.getConnection().prepareStatement(SELECT_ALL);
		ResultSet rSet = stmt.executeQuery();
		while(rSet.next()){
			String codigo = rSet.getString("codigo");
			String descricao = rSet.getString("descricao");
			double rendimento = rSet.getDouble("rendimento");
			double risco = rSet.getDouble("risco");
			int tipo = rSet.getInt("tipo");
			double fatia = rSet.getDouble("fatia");
			double valorMinimo = rSet.getDouble("valorMinimo");
			Aplicacoes Aplicacoess = this.createCarteira(codigo,descricao,risco,rendimento,
					 tipo, fatia,  valorMinimo);
			Aplicacoes.add(Aplicacoess);
		}
		return Aplicacoes;
	}

}
