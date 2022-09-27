<%@ page language="java" contentType="text/html; charset=UTF-8"

    pageEncoding="UTF-8"%>

<%@page import="java.sql.*"%>

<%@page import="DBPKG.Util" %>

<!DOCTYPE html>

<html>

<head>

<meta charset="UTF-8">

<title>회원매출조회</title>

<link rel="stylesheet" href="style.css">

</head>

<body>



<jsp:include page="header.jsp"></jsp:include>



<section >

<h2> <b> 회원매출조회 </b></h2>

<form>

<table border="1">

	<tr>

		<td>회원번호</td>

		<td>회원성명</td>

		<td>고객등급</td>

		<td style="width:50px">매출</td>

	</tr>

	

<% 

request.setCharacterEncoding("UTF-8");

Connection conn = null;

String grade="";

Statement stmt = null;

try {

	conn = Util.getConnection();

	stmt = conn.createStatement();

	

	String sql= "SELECT me.custno, me.custname, me.grade, sum(mo.price) price " +

				"FROM tbl_member_202205 me, tbl_money_202205 mo " +

				"WHERE me.custno = mo.custno " +

				"GROUP BY me.custno, me.custname, me.grade " +

				"ORDER BY sum(mo.price) desc" ;	

	

	ResultSet rs = stmt.executeQuery(sql);

    

	while(rs.next()) {

		grade = rs.getString("grade") ;

		switch(grade) {

		case "A" :

				grade = "VIP";

				break;

			case "B" :

				grade = "일반";

				break;

			case "C" :

				grade = "직원";

				break;

		}



		%>

		<tr>

			<td> <%=rs.getString("custno") %> </td>

			<td> <%=rs.getString("custname") %> </td>

			<td> <%=grade %> </td>

			<td> <%=rs.getString("price") %> </td>

		</tr>

		<% 

	}

}

catch(Exception e){

	e.printStackTrace();

}



%>	

</table>	

</form>

</section>

<jsp:include page="footer.jsp"></jsp:include>

</body>

</html>