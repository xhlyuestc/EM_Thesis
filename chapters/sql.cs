public class SQLHelper  
{	//新建SQLHelper类（支持基本QL语句）
	private SqlConnection sqlCon = null;  
	private SqlCommand cmd = null;  
	private SqlDataReader sdr = null;  
	public SQLHelper()  
	{  
		sqlCon = new SqlConnection(ConfigurationManager .ConnectionStrings["ConnStr"].ConnectionString);  
	}  
	/// <summary>   
	/// 打开数据库连接   
	/// </summary>   
	/// <returns></returns>   
	private SqlConnection GetCon()  
	{  
		if (sqlCon.State==ConnectionState.Closed)  
		{  
		  sqlCon.Open();    
		}  
		return sqlCon;  
	}  
	/// <summary>   
	/// 执行不带参数的增删改sql语句或存储过程   
	/// </summary>   
	/// <param name="cmdText">增删改sql语句或存储过程</param>   
	/// <param name="ct">命令类型</param>   
	/// <returns></returns>   
	public int ExecuteNonQuery(string cmdText, CommandType ct)  
	{  
		int rex;  
		try  
		{  
		SqlCommand sqlcom = new SqlCommand(cmdText,GetCon());  
		sqlcom.CommandType = ct;  
		rex =sqlcom.ExecuteNonQuery();  
		}  
		catch (Exception ex)  
		{  
  
			throw ex;  
		}  
		finally  
		{  
			if (sqlCon.State==ConnectionState.Open)  
			{  
			   sqlCon.Close();    
			}  
		}  
		return rex;  
	}  
	/// <summary>   
	///  执行带参数的增删改SQL语句或存储过程   
	/// </summary>   
	/// <param name="cmdText">增删改SQL语句或存储过程</param>   
	/// <param name="ct">命令类型</param>   
	/// <returns></returns>   
	public int ExecuteNonQuery(string cmdText, SqlParameter[] paras, CommandType ct)  
	{  
		int res;  
		using (cmd = new SqlCommand(cmdText, GetCon()))  
		{  
			cmd.CommandType = ct;  
			cmd.Parameters.AddRange(paras);  
			res = cmd.ExecuteNonQuery();  
		}  
		return res;  
	}  
	/// <summary>   
	///  执行带参数的查询SQL语句或存储过程   
	/// </summary>   
	/// <param name="cmdText">查询SQL语句或存储过程</param>   
	/// <param name="paras">参数集合</param>   
	/// <param name="ct">命令类型</param>   
	/// <returns></returns>   
	public DataTable ExecuteQuery(string cmdText, SqlParameter[] paras, CommandType ct)  
	{  
		DataTable dt = new DataTable();  
		cmd = new SqlCommand(cmdText,GetCon());  
		cmd.CommandType = ct;  
		cmd.Parameters.AddRange(paras);  
		using (sdr = cmd.ExecuteReader(CommandBehavior.CloseConnection))  
		{  
			dt.Load(sdr);  
		}  
		return dt;  
	}  
	/// <summary>   
	/// 执行不带参数的查询SQL语句或存储过程   
	/// </summary>   
	/// <param name="cmdText">查询SQL语句或存储过程</param>   
	/// <param name="ct">命令类型</param>   
	/// <returns></returns>   
	public DataTable ExecuteQuery(string cmdText, CommandType ct)  
	{  
		DataTable dt = new DataTable();  
		cmd = new SqlCommand(cmdText, GetCon());  
		cmd.CommandType = ct;  
		using (sdr = cmd.ExecuteReader(CommandBehavior.CloseConnection))  
		{  
			dt.Load(sdr);  
		}  
		return dt;  
	}  
}  