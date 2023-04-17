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
<title>부서별근무일수집계</title>
</head>
<link href="style.css" rel="stylesheet">
<script src = "check.js"></script>
<body>
<jsp:include page="header.jsp"></jsp:include>
<section>
<h2>부서별근무일수집계</h2>
<table border = "1">
<tr align="center"><td>사원번호</td><td>이름</td><td>부서명</td><td>근무일수</td></tr>
<%
	try {
		Class.forName("oracle.jdbc.OracleDriver");
		Connection con = DriverManager.getConnection("jdbc:oracle:thin:@//localhost:1521/xe", "system", "1234");
		String sql = "select re.empno,empname,deptcode,count(re.empno) "+
				"from tbl_resv_202108 re, tbl_emp_202108 em "+
				"where re.empno = em.empno " +
				"group by re.empno,empname,deptcode "+
				"order by re.empno ";
		PreparedStatement p = con.prepareStatement(sql);
		ResultSet rs = p.executeQuery();
		while(rs.next()){
%>
	<tr align="center"><td><%=rs.getString(1) %></td>
	<td><%=rs.getString(2) %></td>
	<td><%=rs.getString(3) %></td>
	<td><%=rs.getString(4) %></td></tr>
	<%
	}
		%>
	</table>
</section>
<jsp:include page="footer.jsp"></jsp:include>
<%
}
catch(Exception e){
		e.printStackTrace();
}
%>