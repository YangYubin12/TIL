<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@page import="DBPKG.Util"%>
<%@page import="java.sql.*"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>회원정보수정</title>
<link rel="stylesheet" href="style.css">
<script type="text/javascript" src="check.js"></script>
</head>
<body>
<script type="text/javascript">
function modify(){
	alert("회원정보수정이 완료되었습니다!") ;
	document.frm2.submit();
}
</script>
<jsp:include page="header.jsp"></jsp:include>

<section >
<h2> <b> 홈쇼핑 회원 정보 수정 </b></h2>
<form method = "post" action = "action.jsp" name=frm2 >
 		<input type="hidden"  name="mode" value="modify">
<table border="1">
<%
request.setCharacterEncoding("UTF-8");
String custno = request.getParameter("custno") ;
Connection conn = null;
try {
    conn = Util.getConnection();
	String sql = "SELECT * FROM tbl_member_202205 WHERE custno = ?" ;
	PreparedStatement pstmt = conn.prepareStatement(sql);
	pstmt.setString(1, custno);
	ResultSet rs = pstmt.executeQuery();
	rs.next();	

%>
	<tr>
		<td><b>회원번호</b></td>
		<td><input type="text" name="custno" value="<%=rs.getString(1)%>" readonly> </td>
	</tr>
	<tr>
		<td><b>회원성명</b></td>
		<td><input type="text" name="custname" value="<%=rs.getString(2)%>"></td>
	</tr>
	<tr>
		<td><b>회원전화</b></td>
		<td><input type="text" name="phone" value="<%=rs.getString(3)%>"></td>
	</tr>
	<tr>
		<td><b>회원주소</b></td>
		<td><input type="text" name="address" value="<%=rs.getString(4)%>"></td>
	</tr>
	<tr>
		<td><b>가입일자</b></td>
		<td><input type="text" name="joindate" value="<%=rs.getDate(5)%>"></td>
	</tr>
	<tr>
		<td><b>고객등급[A:VIP,B:일반,C:직원]</b></td>
		<td><input type="text" name="grade" value="<%=rs.getString(6)%>"></td>
	</tr>
	<tr>
		<td><b>도시코드</b></td>
		<td><input type="text" name="city" value="<%=rs.getString(7)%>"></td>
	</tr>
	<tr>
		<td colspan="2">
		<input type="button" value="수정" onclick="return modify()"> 
		<input type="button" value="조회" onclick="window.location = 'list.jsp'">
		</td>
	</tr>
<%
} 
catch(Exception e) {
		e.printStackTrace();
}
%>
</table>
</form>
</section>

<jsp:include page="footer.jsp"></jsp:include>

</body>