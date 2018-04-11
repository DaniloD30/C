package classes;

public abstract class Aplicacoes {
	
	private String codigo;
	private String descricao;
	private float estimativaDeRisco;
	private float estimativaDeRendimento;
	private float fatia;
	private float valorMinimo;
	
	
	public Aplicacoes(String codigo, String descricao, float estimativaDeRisco, float estimativaDeRendimento,
			float fatia, float valorMinimo) {
		super();
		this.codigo = codigo;
		this.descricao = descricao;
		this.estimativaDeRisco = estimativaDeRisco;
		this.estimativaDeRendimento = estimativaDeRendimento;
		this.fatia = fatia;
		this.valorMinimo = valorMinimo;
	}
	public float getValorMinimo() {
		return valorMinimo;
	}
	public void setValorMinimo(float valorMinimo) {
		this.valorMinimo = valorMinimo;
	}
	public float getFatia() {
		return fatia;
	}
	public void setFatia(float fatia) {
		this.fatia = fatia;
	}
	public float getEstimativaDeRisco() {
		return estimativaDeRisco;
	}
	public void setEstimativaDeRisco(float r) {
		this.estimativaDeRisco = r;
	}
	public float getEstimativaDeRendimento(){
		return estimativaDeRendimento;
	}
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
