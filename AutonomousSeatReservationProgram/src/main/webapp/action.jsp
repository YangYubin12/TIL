<%@page import="java.sql.*" %>
<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%
	request.setCharacterEncoding("UTF-8");
	String resvno = request.getParameter("resvno");
	String empno = request.getParameter("empno");
	String resvdate = request.getParameter("resvdate");
	String seatno = request.getParameter("seatno");
	try {
		Class.forName("oracle.jdbc.OracleDriver");
		Connection con = DriverManager.getConnection("jdbc:oracle:thin:@//localhost:1521/xe", "system", "1234");
		String sql = "insert into TBL_RESV_202108 values(?,?,?,?)";
		PreparedStatement p = con.prepareStatement(sql);
		p.setString(1, resvno);
		p.setString(2, empno);
		p.setString(3, resvdate);
		p.setString(4, seatno);
		p.executeUpdate();
	}
	catch(Exception e){
		e.printStackTrace();
	}
%>
<jsp:forward page="reserve.jsp"></jsp:forward>