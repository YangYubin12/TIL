<%@page import="java.sql.*" %>
<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%
	request.setCharacterEncoding("UTF-8");
	String empno = request.getParameter("empno");
	System.out.println(empno);
%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>자율좌석예약 프로그램</title>
</head>
<link href="style.css" rel="stylesheet">
<script src = "check.js"></script>
<body>
<jsp:include page="header.jsp"></jsp:include>
<section>
<h2>사원번호 : <%=empno %>님의 좌석예약 조회</h2>
<table border = "1">
<tr align="center"><td>사원번호</td><td>이름</td><td>근무일자</td><td>좌석번호</td><td>좌석위치</td><td>내선번호</td></tr>
<%
	try {
		Class.forName("oracle.jdbc.OracleDriver");
		Connection con = DriverManager.getConnection("jdbc:oracle:thin:@//localhost:1521/xe", "system", "1234");
		String sql = "select re.empno,empname,resvdate,re.seatno,office,callno "+
				"from tbl_resv_202108 re, tbl_emp_202108 em,tbl_seat_202108 se "+
				"where re.empno = ? and re.empno = em.empno " +
				"and re.seatno = se.seatno ";
		PreparedStatement p = con.prepareStatement(sql);
		p.setString(1, empno);
		ResultSet rs = p.executeQuery();
		while(rs.next()){
%>
	<tr align="center"><td><%=rs.getString(1) %></td>
	<td><%=rs.getString(2) %></td>
	<td><%=rs.getString(3) %></td>
	<td><%=rs.getString(4) %></td>
	<td><%=rs.getString(5) %></td>
	<td><%=rs.getString(6) %></td> </tr>
	<%
	}
		%>
	</table>
	<input type = "button" value="돌아가기" onclick="window.location='list.jsp'">
</section>
<jsp:include page="footer.jsp"></jsp:include>
<%
}
catch(Exception e){
		e.printStackTrace();
}
%>