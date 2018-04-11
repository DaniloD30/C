package classes;

public abstract class Aplicacoes {
	
	private String codigo;
	private String descricao;
	protected double estimativaDeRisco;
	protected double estimativaDeRendimento;
	private double fatia;
	private double valorMinimo;
	
	
	public Aplicacoes(String codigo, String descricao, double estimativaDeRisco, double estimativaDeRendimento,
			double fatia, double valorMinimo) {
		super();
		this.codigo = codigo;
		this.descricao = descricao;
		this.estimativaDeRisco = estimativaDeRisco;
		this.estimativaDeRendimento = estimativaDeRendimento;
		this.fatia = fatia;
		this.valorMinimo = valorMinimo;
	}
	public Aplicacoes(){
	}
	public double getValorMinimo() {
		return valorMinimo;
	}
	public void setValorMinimo(float valorMinimo) {
		this.valorMinimo = valorMinimo;
	}
	public double getFatia() {
		return fatia;
	}
	public void setFatia(float fatia) {
		this.fatia = fatia;
	}
	public abstract double getEstimativaDeRisco() ;
		
	public void setEstimativaDeRisco(float r) {
		this.estimativaDeRisco = r;
	}
	public abstract double getEstimativaDeRendimento();
		
	public void setEstimativaDeRendimento(float r) {
		this.estimativaDeRendimento = r;
	}
	
	public String getCodigo() {
		return codigo;
	}
	public void setCodigo(String codigo) {
		this.codigo = codigo;
	}
	public String getDescricao() {
		return descricao;
	}
	public void setDescricao(String descricao) {
		this.descricao = descricao;
	}
	
	
	
}
