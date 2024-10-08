<%@ page contentType="text/html; charset=utf-8"%>
<%@ page import="java.util.ArrayList"%>
<%@ page import="dto.Product"%>
<%@ page import="dao.ProductRepository"%>
<jsp:useBean id="productDAO" class="dao.ProductRepository" scope="session"></jsp:useBean>
<html>
<head>
<link rel="stylesheet"
     href="https://cdn.jsdelivr.net/npm/bootstrap@4.6.1/dist/css/bootstrap.min.css">
     <title>상품 목록</title>
</head>
<body>
     <jsp:include page ="menu.jsp"/>
     <div class="jumbotron">
     <div class = "container">
     <h1 class="display-3">상품 목록</h1>
     </div>
     </div>
     <% 
     ProductRepository dao = ProductRepository.getInstance();
      ArrayList<Product> listOfProducts = dao.getAllProducts();
     %>
     
     <div class="container">
     <div class="row" align="center">
     <%
        for(int i =0; i<listOfProducts.size(); i++){
        	Product product = listOfProducts.get(i);
     %>	
     <div class="col-md-4">
     <img src="c:\\upload/<%=product.getFilename()%>"
     style="width:100%">
         <h3><%=product.getPname() %></h3>
         <p><%=product.getDescription() %>
         <p><%=product.getUnitPrice() %>원
         <p> <a href = "./product.jsp?id=<%=product.getProductId() %>"
         class="btn btn-secondary" role="button"> 상세 정보 &raquo;</a>
     </div>
     <% 
          }
     %>
     </div>
      <div style="position: absolute; right: 0px; bottom:0px;"></div> 
      <a href = "./welcome.jsp" class="btn btn-secondary" > 메인 화면 &raquo;</a>
     <hr>
     </div>
     <jsp:include page="footer.jsp"></jsp:include>
</body>
</html>