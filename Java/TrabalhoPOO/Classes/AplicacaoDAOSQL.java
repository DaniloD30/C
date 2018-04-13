package br.edu.ifba.inf008.contabil.dao.sql;

import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.Collection;

import br.edu.ifba.inf008.contabil.dao.ContaDAOIF;
import br.edu.ifba.inf008.contabil.model.Ativo;
import br.edu.ifba.inf008.contabil.model.Conta;
import br.edu.ifba.inf008.contabil.model.Passivo;
import br.edu.ifba.inf008.contabil.model.PatrimonioLiquido;
import br.edu.inf008.contabil.exceptions.ContaNaoExistenteException;

public class AplicacaoDAOSQL extends AbstractDAOSQL implements ContaDAOIF{

	
  
	
	private static final String SELECT_ALL = "SELECT codigo, descricao, rendimento, risco, tipo FROM APLICACAO";
	private static final String SELECT_ALL_CARTEIRA = "SELECT ";//inner join
	
	private Carteira createConta(String codigo, String descricao, double rendimento, double risco, int tipo) {
		Carteira carteira = null;
		if(tipo == Conta.PRIMARIA)
			carteira = new Primaria(id, nome);
		else if(tipo == Conta.CARTEIRA) {
			carteira = new Carteira(codigo, descricao, rendimento, risco);
			Collection<Conta> aplicacoes = this.retrieveAplicacoes(codigo);
			carteira.setAplicacoes(aplicacoes);
		}
		return conta;
	}
	
	private Collection<Conta> retrieveAplicacoes() {
		Collection <Conta> contas = new ArrayList<Conta>();
		PreparedStatement stmt = this.getConnection().prepareStatement(SELECT_ALL);
		ResultSet rSet = stmt.executeQuery();
		while(rSet.next()){
			String codigo = rSet.getString("codigo");
			String descricao = rSet.getString("descricao");
			double rendimento = rSet.getDouble("rendimento");
			double risco = rSet.getDouble("risco");
			int tipo = rSet.getInt("tipo");
			Conta conta = this.createConta(codigo, descricao, rendimento, risco, tipo);
			contas.add(conta);
		}
		return contas;
	}
	
	private int getTipo(Conta conta) {
		if(conta.getClass() == Ativo.class)
			return Conta.ATIVO;
		else if(conta.getClass() == Passivo.class)
			return Conta.PASSIVO;
		else if(conta.getClass() ==  PatrimonioLiquido.class)
			return Conta.PATRIMONIO_LIQUIDO;
		return -1;
	}

	@Override
	public Collection<Conta> buscarTodos() throws Exception {
		Collection <Conta> contas = new ArrayList<Conta>();
		PreparedStatement stmt = this.getConnection().prepareStatement(SELECT_ALL);
		ResultSet rSet = stmt.executeQuery();
		while(rSet.next()){
			String codigo = rSet.getString("codigo");
			String descricao = rSet.getString("descricao");
			double rendimento = rSet.getDouble("rendimento");
			double risco = rSet.getDouble("risco");
			int tipo = rSet.getInt("tipo");
			Conta conta = this.createConta(codigo, descricao, rendimento, risco, tipo);
			contas.add(conta);
		}
		return contas;
	}

}
