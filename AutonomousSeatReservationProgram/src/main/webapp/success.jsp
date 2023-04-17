<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ page import = "java.sql.*" %>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
<link rel = "stylesheet" href = "style.css">
</head>
<body>
	<jsp:include page = "header.jsp"/>
	<section>
	<%
	request.setCharacterEncoding("UTF-8");
	String empno = request.getParameter("empno");
	%>
		<h2>사원번호 : <%= empno%> 님의 좌석 예약 조회</h2>
		
	<form>
		<table border =1 >
			<tr>
				<td>사원번호</td>
				<td>이름</td>
				<td>근무일자</td>
				<td>좌석번호</td>
				<td>좌석위치</td>
				<td>내선번호</td>
			</tr>
			
			<%
			try{
				Class.forName("oracle.jdbc.OracleDriver");
				Connection con = DriverManager.getConnection("jdbc:oracle:thin:@//localhost:1521/xe", "system", "1234");
				String sql = "select em.empno, empname, resvdate, re.seatno, office, callno from tbl_emp_202108 em, tbl_seat_202108 se, tbl_resv_202108 re where em.empno = re.empno and se.seatno = re.seatno and re.empno=? ";
				PreparedStatement pstmt = con.prepareStatement(sql);
				pstmt.setString(1, empno);
				ResultSet rs = pstmt.executeQuery();
				while(rs.next()){
					
					String resvdate = rs.getString(3);
					String date = resvdate.substring(0,4)+"년"+resvdate.substring(4,6)+"월"+resvdate.substring(6,8)+"일";
					%>
					<tr>
					<td><%=rs.getString(1) %></td>
					<td><%=rs.getString(2) %></td>
					<td><%=date %></td>
					<td><%=rs.getString(3) %></td>
					<td><%=rs.getString(4) %></td>
					<td><%=rs.getString(5) %></td>
					</tr>
					<%
				}
			}catch(Exception e){
				e.printStackTrace();
			}
					%>
					
		</table>
	</form>
	<p style="text-align: center"><input type= button value="돌아가기" onclick = "window.location = 'list.jsp'"></p>
	</section>
	
	<jsp:include page = "footer.jsp"/>
</body>
</html>