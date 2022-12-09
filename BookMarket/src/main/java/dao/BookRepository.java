package dao;

import java.util.ArrayList;

import dto.Book;

public class BookRepository {
	 private ArrayList<Book> listOfBooks = new ArrayList<Book>();
	  private static BookRepository instance = new BookRepository();
	  
	  public static BookRepository getInstance() {
		  return instance;
	  }
	 
	  public BookRepository() {
		  Book book1 = new Book("P1234", "HTML5+CSS3", 15000);
		  book1.setAuthor("황재호");
		  book1.setDescription("워드나 PPT 문서를 만들 수 있나요? 그러면 문제 없습니다. 지금 바로 웹페이지 제작에 도전해보세요. 지금 당장 컴퓨터가 없어도 괜찮습니다. 코드와 실행 화면이 바로 보여서 눈으");
		  book1.setPublisher("한빛미디어");
		  book1.setCategory("Hello Coding");
		  book1.setUnitsInStock(40);
		  book1.setTotalPages(260);
		  book1.setReleaseDate("2016.3.15");
		  book1.setCondition("New");
		  
		  Book book2 = new Book("P1235", "쉽게 배우는 자바 프로그래밍",27000);
		  book2.setAuthor("우종중");
		  book2.setDescription("객체 지향의 핵심과 자바의 현대적 기능을 충실히 다루면서도 초보자가 쉽게 학습할 수 있게 구성했습니다. 시각화 도구를 활용한 개념 설명과 군더더기 없는 핵심 코드를 통해 개념을 구현");
		  book2.setPublisher("한빛아카데미");
		  book2.setCategory("IT모바일");
		  book2.setUnitsInStock(60);
		  book2.setTotalPages(190);
		  book2.setReleaseDate("2016.3.15");
		  book2.setCondition("Refurbished");
		  
		  Book book3 = new Book("P1236", "스프링4 입문", 27000);
		  book3.setAuthor("하세가와 유이치, 오오노 와타루, 토키 코헤이(권은철, 전민수)");
		  book3.setDescription("스프링은 단순히 사용 방법만 익히는 것보다 아키텍처를 어떻게 이해하고 설계하는지가 더 중요합니다. 예제를 복사해서 붙여넣는 방식으로는 실제 개발에서 스프링을 제대로 활용할 수 없습니다");
		  book3.setPublisher("한빛미디어");
		  book3.setCategory("IT모바일");
		  book3.setUnitsInStock(50);
		  book3.setTotalPages(310);
		  book3.setReleaseDate("2016.3.15");
		  book3.setCondition("Old");
		  
		  listOfBooks.add(book1);
		  listOfBooks.add(book2);
		  listOfBooks.add(book3);

	  }
	  
	  public ArrayList<Book> getAllBooks(){
		  return listOfBooks;
	  }
	  public  Book getBookById(String bookId) {
		  Book  bookById = null;
		   
		   for(int i = 0; i <listOfBooks.size(); i++) {
			   Book book = listOfBooks.get(i);
			   if(book != null && book.getbookId() != null && book.getbookId().equals(bookId)) {
				   bookById = book;
				   break;
			   }
		   }
		   return bookById;
	  }
	  public void addBook(Book book) {
		   listOfBooks.add(book);
	  }
}
