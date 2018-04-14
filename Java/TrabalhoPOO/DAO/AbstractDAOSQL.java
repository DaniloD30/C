package dao;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

public abstract class AbstractDAOSQL {

	private static final String URI = "jdbc:postgresql://localhost:5432/postgres";
	private static final String USER = "postgres";
	private static final String PWD = "aluno";
	
	protected Connection getConnection() throws SQLException{
		DriverManager.registerDriver(new org.postgresql.Driver());
		return DriverManager.getConnection(AbstractDAOSQL.URI, AbstractDAOSQL.USER, AbstractDAOSQL.PWD);
	}
		
	
}
