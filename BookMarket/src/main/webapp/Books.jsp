<%@ page contentType="text/html; charset=utf-8"%>
<%@ page import="java.util.ArrayList"%>
<%@ page import="dto.Book"%>
<%@ page import="dao.BookRepository"%>
<jsp:useBean id="bookDAO" class="dao.BookRepository" scope="session"></jsp:useBean>
<html>
<head>
<link rel="stylesheet"
     href="https://cdn.jsdelivr.net/npm/bootstrap@4.6.1/dist/css/bootstrap.min.css">
     <title>도서 목록</title>
</head>
<body>
     <jsp:include page ="menu.jsp"/>
     <div class="jumbotron">
     <div class = "container">
     <h1 class="display-3">도서 목록</h1>
     </div>
     </div>
     <% 
     BookRepository dao = BookRepository.getInstance();
      ArrayList<Book> listOfBooks = dao.getAllBooks();
     %>
     <div class="container">
     <div class="col" align="left">
     <%
        for(int i =0; i<listOfBooks.size(); i++){
        	Book book = listOfBooks.get(i);
     %>	
     <div class="col-1g" style="padding-top: 20px">
   
       <h4>[<%=book.getCategory() %>] <%=book.getName() %></h4><p>
                <p><%=book.getDescription()%>...
                 <a href="./book.jsp?id=<%=book.getbookId() %>"
                class="btn btn-secondary" role="button">상세 정보 &raquo;</a>
                <p><%=book.getAuthor() %>|<%=book.getPublisher() %>|<%=book.getUnitPrice() %>원
            </div>
            <hr>
       <% }%>     
     </div>
     </div>
     <jsp:include page="footer.jsp"></jsp:include>
</body>
</html>