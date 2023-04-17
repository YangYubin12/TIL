<%@page import="java.sql.*" %>
<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%
	request.setCharacterEncoding("UTF-8");
	String empno = request.getParameter("empno");
	System.out.println(empno);
	try {
		Class.forName("oracle.jdbc.OracleDriver");
		Connection con = DriverManager.getConnection("jdbc:oracle:thin:@//localhost:1521/xe", "system", "1234");
		String sql = "select * "+
				"from tbl_emp_202108 "+
				"where empno=? " ;
		
		PreparedStatement p = con.prepareStatement(sql);
		p.setString(1, empno);
		ResultSet rs = p.executeQuery();
		if(rs.next()){
			empno = rs.getString(1);
			%>
			<jsp:forward page = "success.jsp"></jsp:forward>
			<%
		}
		else{
			%>
			<jsp:forward page = "fail.jsp"></jsp:forward>
			<%
		}
	}
	catch(Exception e){
			e.printStackTrace();
	}
%>