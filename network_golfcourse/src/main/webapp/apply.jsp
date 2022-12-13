<%@ page language="java" contentType="text/html; charset=EUC-KR"
    pageEncoding="utf-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>Insert title here</title>
</head>
<body>
	<script type="text/javascript" src="check.js"></script>
	<jsp:include page="header.jsp"></jsp:include>
	<section>
		<h1>수강신청</h1>
		<form name="frm" method="post" action="action.jsp">
			<table border="1">
				<tr>
					<td>수강일</td>
					<td><input type="text" name="date">2022년03월 예)202203</td>
				</tr>
				<tr>
					<td>회원명</td>
					<td>
						<select name="memberName" onchange="getNumber(this.value)">
							<option value="">회원명</option>
							<option value="10001">홍길동</option>
							<option value="10002">장발장</option>
							<option value="10003">임꺽정</option>
							<option value="20001">성춘향</option>
							<option value="20002">이몽룡</option>
						</select>
					</td>
				</tr>
				<tr>
					<td>회원번호</td>
					<td><input type="text" name="number" readonly>예)100001</td>
				</tr>
				<tr>
					<td>강의장소</td>
					<td>
						<select name="area">
							<option value="">강의장소</option>
							<option value="서울본원">서울본원</option>
							<option value="성남본원">성남본원</option>
							<option value="대전본원">대전본원</option>
							<option value="부산본원">부산본원</option>
							<option value="대구본원">대구본원</option>
						</select>
					</td>
				</tr>
				<tr>
					<td>강의명</td>
					<td>
						<select name="className" onchange="getPrice(this.value)">
							<option value="">강의명</option>
							<option value="100000">초급반</option>
							<option value="200000">중급반</option>
							<option value="300000">고급반</option>
							<option value="400000">심화반</option>
						</select>
					</td>
				</tr>
				<tr>
					<td>수강료</td>
					<td><input type="text" name="price">원</td>
				</tr>
				<tr>
					<td colspan="2">
						<input type="button" value="수강신청" onclick="return checking()">
						<input type="button" value="다시쓰기" onclick="return reseting()">
					</td>
				</tr>
			</table>
		</form>
	</section>
	<jsp:include page="footer.jsp"></jsp:include>
</body>
</html>