<%@page import="java.sql.*" %>
<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%
    Class.forName("oracle.jdbc.OracleDriver");
    Connection con = DriverManager.getConnection("jdbc:oracle:thin:@//localhost:1521/xe","system","1234");
    request.setCharacterEncoding("UTF-8");
    
    String date = request.getParameter("price");
    String number = request.getParameter("number");
    String area = request.getParameter("area");
    int price = Integer.parseInt(request.getParameter("price"));
    int className = Integer.parseInt(request.getParameter("className")) /1000;
    try{
        String sql = "INSERT INTO tbl_class_202201 VALUES(?, ?, ?, ?, ?)";
        PreparedStatement pstmt = con.prepareStatement(sql);
        pstmt.setString(1, date);
        pstmt.setString(2, number);
        pstmt.setString(3, area);
        pstmt.setInt(4, price);
        pstmt.setString(5, Integer.toString(className));
    }catch(Exception e){
        e.printStackTrace();
    }
%>

<jsp:forward page="index.jsp" />