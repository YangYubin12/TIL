<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>자율좌석예약 프로그램</title>
</head>
<link href="style.css" rel="stylesheet">
<body>
<jsp:include page="header.jsp"></jsp:include>
<section>
<h2>근무좌석예약</h2>
<form name = "frm2" method = "POST" action ="list2.jsp">
<table border = "1">
<tr><td>사원번호를 입력하시오.</td><td>
<input type = "text" name = "empno"></td></tr>
<tr>
<td colspan="2"  align="center">
<input type = "submit" value="좌석예약조회" onclick="listcheck()">
<input type = "button" value="홈으로" onclick="window.location='index.jsp'">
</td>
</tr>
</table>
</form>
<script src = "check.js"></script>
</section>
<jsp:include page="footer.jsp"></jsp:include>
</body>
</html>