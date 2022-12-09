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
		  book1.setAuthor("Ȳ��ȣ");
		  book1.setDescription("���峪 PPT ������ ���� �� �ֳ���? �׷��� ���� �����ϴ�. ���� �ٷ� �������� ���ۿ� �����غ�����. ���� ���� ��ǻ�Ͱ� ��� �������ϴ�. �ڵ�� ���� ȭ���� �ٷ� ������ ����");
		  book1.setPublisher("�Ѻ��̵��");
		  book1.setCategory("Hello Coding");
		  book1.setUnitsInStock(40);
		  book1.setTotalPages(260);
		  book1.setReleaseDate("2016.3.15");
		  book1.setCondition("New");
		  
		  Book book2 = new Book("P1235", "���� ���� �ڹ� ���α׷���",27000);
		  book2.setAuthor("������");
		  book2.setDescription("��ü ������ �ٽɰ� �ڹ��� ������ ����� ����� �ٷ�鼭�� �ʺ��ڰ� ���� �н��� �� �ְ� �����߽��ϴ�. �ð�ȭ ������ Ȱ���� ���� ����� �������� ���� �ٽ� �ڵ带 ���� ������ ����");
		  book2.setPublisher("�Ѻ���ī����");
		  book2.setCategory("IT�����");
		  book2.setUnitsInStock(60);
		  book2.setTotalPages(190);
		  book2.setReleaseDate("2016.3.15");
		  book2.setCondition("Refurbished");
		  
		  Book book3 = new Book("P1236", "������4 �Թ�", 27000);
		  book3.setAuthor("�ϼ����� ����ġ, ������ ��Ÿ��, ��Ű ������(����ö, ���μ�)");
		  book3.setDescription("�������� �ܼ��� ��� ����� ������ �ͺ��� ��Ű��ó�� ��� �����ϰ� �����ϴ����� �� �߿��մϴ�. ������ �����ؼ� �ٿ��ִ� ������δ� ���� ���߿��� �������� ����� Ȱ���� �� �����ϴ�");
		  book3.setPublisher("�Ѻ��̵��");
		  book3.setCategory("IT�����");
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
