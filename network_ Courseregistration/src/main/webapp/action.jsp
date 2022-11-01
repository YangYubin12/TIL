 <%@page import="DBPKG.Util"%>
  <%@page import="java.sql.*"%>
  <%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
  <%
  request.setCharacterEncoding("UTF-8");
  String mode = request.getParameter("mode");
  String id = request.getParameter("id");
  String name = request.getParameter("name");
  String credit = request.getParameter("credit");
  String lecturer = request.getParameter("lecturer");
  String week = request.getParameter("week");
  String start_hour = request.getParameter("start_hour");
  String end_hour = request.getParameter("end_hour");
  try{
	Connection conn = Util.getConnection();
	String sql = "";
	PreparedStatement pstmt = null;
	switch(mode){
	case "insert":
	sql = "INSERT INTO course_tbl VALUES(?,?,?,?,?,?,?)";	
	pstmt = conn.prepareStatement(sql);
	pstmt.setString(1, id);
	pstmt.setString(2, name);
	pstmt.setString(3, credit);
	pstmt.setString(4, lecturer);
	pstmt.setString(5, week);
	pstmt.setString(6, start_hour);
	pstmt.setString(7, end_hour);
    pstmt.executeUpdate(); 
	%>
    <jsp:forward page="insert.jsp"></jsp:forward>
    <% 	
    break;
    case "modify":
    	sql ="UPDATE course_tbl SET name=?, credit=?, lecturer=?, week=?, start_hour=?, end_hour=?  WHERE id=?";
    	pstmt = conn.prepareStatement(sql);
    	pstmt.setString(1, name);
    	pstmt.setString(2, credit);
    	pstmt.setString(3, lecturer);
    	pstmt.setString(4, week);
    	pstmt.setString(5, start_hour);
    	pstmt.setString(6, end_hour);
    	pstmt.setString(7, id);
    	
    	pstmt.executeUpdate();			 
    	%>
    	 <jsp:forward page="modify.jsp"></jsp:forward>
    	 <%
    	 break;
    	 case "delete":
    		 sql = "DELETE FROM course_tbl WHERE id=?";
    		 pstmt = conn.prepareStatement(sql);
    		 pstmt.setString(1, id);
    		 pstmt.executeUpdate();
    	 %>
    	 <jsp:forward page = "list.jsp"></jsp:forward>
    	 <%
    	 break;   	
  	}
 	}  	
catch(Exception e){
	e.printStackTrace();
}
%>