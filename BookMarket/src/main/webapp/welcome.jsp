<%@ page language="java" contentType="text/html; charset=utf-8"
    pageEncoding="utf-8"%>

<html>
<head>
<link rel = "stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap@4.6.1/dist/css/bootstrap.min.css">
<title>Welcome</title>
</head>
<body>


<jsp:include page ="menu.jsp" flush ="false"/>

 <%! String greeting = "Welcome to Book Market Mall"; 
     String tagline = "Welcome to Book Market!"; %>
      <a href = "./addBook.jsp" class="btn btn-secondary" > 도서 등록 &raquo;</a>  
       <a href = "./Books.jsp" class="btn btn-secondary" > 도서 목록 &raquo;</a> 
     <div class = "jumbotron">
     <div class = "container">
     <hi class = "display-3">
           <%= greeting %>
     </h1>
  </div>
</div>
     <div class = "container">
     <div class = "text-center">
      <h3>
      <%= tagline %>
      </h3>
     </div>
   <hr>
</div>

  <jsp:include page ="footer.jsp" flush ="false"/>
</body>
</html>