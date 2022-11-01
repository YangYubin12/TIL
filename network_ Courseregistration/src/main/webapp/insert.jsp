<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>insert</title>
<link href="style.css" rel="stylesheet">
</head>
<body>
<script type="text/javascript" src="check.js"></script>
<jsp:include page="header.jsp"></jsp:include>
<section>
<h1>교과목 추가</h1>
<form method="post" action="action.jsp" name="frm">
<input type="hidden" name="mode" value="insert">
<table border="1">
<tr>
<td>과목 코드</td>
<td><input type="text" name="id"></td>
</tr>
<tr>
<td>과목명</td>
<td><input type="text" name="name"></td>
</tr>
<tr>
<td>학점</td>
<td><input type="text" name="credit"></td>
</tr>
<tr>
<td>담당강사</td>
<td><select name="lecturer" style="width: 100%">
<option value="">담당강사선택</option>
<option value="1">김교수</option>
<option value="2">이교수</option>
<option value="3">박교수</option>
<option value="4">우교수</option>
<option value="5">최교수</option>
<option value="6">임교수</option>
</select>
</td>
</tr>
<tr>
<td>요일</td>
<td><input type="radio" name="week" value="1">월
<input type="radio" name="week" value="2">화
<input type="radio" name="week" value="3">수
<input type="radio" name="week" value="4">목
<input type="radio" name="week" value="5">금
</td>
</tr>
<tr>
<td>시작 시간</td>
<td><input type="text" name="start_hour"></td>
</tr>
<tr>
<td>종료 시간</td>
<td><input type="text" name="end_hour"></td>
</tr>
<tr>
<td colspan="2">
<input type="button" value="추가" onclick="return addCheck()">
<input type="button" value="목록" onclick="return search()">
</td>
</tr>
</table>

</form>
</section>
<jsp:include page="footer.jsp"></jsp:include>
</body>
</html>