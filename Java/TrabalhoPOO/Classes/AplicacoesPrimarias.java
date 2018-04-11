package classes;

public class AplicacoesPrimarias extends Aplicacoes {

	public AplicacoesPrimarias(String codigo, String descricao, double estimativaDeRisco, double estimativaDeRendimento,
			double fatia, double valorMinimo) {
		super(codigo, descricao, estimativaDeRisco, estimativaDeRendimento, fatia, valorMinimo);
		// TODO Auto-generated constructor stub
	}
	public double getEstimativaDeRisco() {
		return estimativaDeRisco;
	}
	public double getEstimativaDeRendimento(){
		return estimativaDeRendimento;
	}

}
