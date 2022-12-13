<%@page import="DBPKG.Util"%>
<%@page import="java.sql.*"%>
<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>list</title>
<link rel="stylesheet" href="style.css">
</head>
<body>
<jsp:include page="header.jsp"/>
<section>
<h1>강사조회</h1>
   <table border="1">
       <tr>
           <td>강사코드</td><td>강사명</td><td>강의명</td><td>수강료</td><td>강사자격취득일</td>
       </tr>
<%
try {
   Connection con = Util.getConnection();
   String sql = "SELECT * from tbl_teacher_202201 order by teacher_code";
   Statement stmt = con.createStatement();
   ResultSet rs = stmt.executeQuery(sql);
   
   while(rs.next()) {
%>
       <tr>
           <td><%=rs.getInt(1) %></td>
           <td><%=rs.getString(2) %></td>
           <td><%=rs.getString(3) %></td>
           <td><%=rs.getInt(4) %></td>
           <td><%=rs.getString(5) %></td>         
       </tr>
<%
   }
} catch(Exception e) {
   e.printStackTrace();
}
%>
   </table>
</section>
<jsp:include page="footer.jsp"/>
</body>
</html>