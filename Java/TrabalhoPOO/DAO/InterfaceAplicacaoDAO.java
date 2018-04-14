package dao;

import java.util.Collection;


public interface InterfaceAplicacaoDAO {
//FALTA COLOCAR OS METÓDOS ...
	public Conta buscarPeloNome(String nomeContaCredito) throws ContaNaoExistenteException;
	public void salvar(Conta conta) throws Exception;
	public void criar(Conta conta) throws Exception;
	public Conta buscarPeloId(String string) throws Exception;
	public Collection<Conta> buscarTodos() throws Exception;
}
