package src;
// Step 4
// 클라이언트 간의 채팅에서 특정 클라이언트와의 귓속말 구현
// 다음의 형식으로 귓속말 전송
// /w 상대방아이디 대화말
// package Server;
import java.io.*;
import java.net.*;
import java.util.*;
import java.util.List;
import java.awt.*;
import java.awt.event.*;

public class MultiChatS_login extends Frame {
   TextArea display;
   Label info;
   List<WhisperThread> list;
   Hashtable hash;
   public WhisperThread SThread;
	
   public MultiChatS_login() {
      super("서버");
      info = new Label();
      add(info, BorderLayout.CENTER);
      display = new TextArea("", 0, 0, TextArea.SCROLLBARS_VERTICAL_ONLY);
      display.setEditable(false);
      add(display, BorderLayout.SOUTH);
      addWindowListener(new WinListener());
      setSize(400,300);
      setVisible(true);
   }
	
   public void runServer() {
      ServerSocket server;
      Socket sock;
      WhisperThread SThread;
      try {
         server = new ServerSocket(5000, 100);
         hash = new Hashtable();
         list = new ArrayList<WhisperThread>();
         try {
            while(true) {
               sock = server.accept();
               SThread = new WhisperThread(this, sock, display, info);
               SThread.start();
               info.setText(sock.getInetAddress().getHostName() + " 서버는 클라이언트와 연결됨");
            }
         } catch(IOException ioe) {
            server.close();
            ioe.printStackTrace();
         }
      } catch(IOException ioe) {
         ioe.printStackTrace();
      }
			
   }

   public static void main(String args[]) {
      MultiChatS_login s = new MultiChatS_login();
      s.runServer();
   }
		
   class WinListener extends WindowAdapter {
      public void windowClosing(WindowEvent e) {
         System.exit(0);
      }
   }
}

class WhisperThread extends Thread {
   Socket sock;
   BufferedWriter output;
   BufferedReader input;
   TextArea display;
   Label info;
   TextField text;
   String clientdata;
   String serverdata = "";
   MultiChatS_login cs;
	
   private static final String SEPARATOR = "|";
   private static final int REQ_LOGON = 1001;
   private static final int REQ_SENDWORDS = 1021;
   private static final int REQ_WISPERSEND = 1022;

   public WhisperThread(MultiChatS_login c, Socket s, TextArea ta, Label l) {
      sock = s;
      display = ta;
      info = l;
      cs = c;
      try {
         input = new BufferedReader(new InputStreamReader(sock.getInputStream()));
         output = new BufferedWriter(new OutputStreamWriter(sock.getOutputStream()));
      } catch(IOException ioe) {
         ioe.printStackTrace();
      }
   }
   public void run() {
	   //clientdata은 "1001|아이디" 또는
	   //1021|보낸사람아이디|대화말
      try {   
    	  cs.list.add(this);
         while((clientdata = input.readLine()) != null) {
            StringTokenizer st = new StringTokenizer(clientdata, SEPARATOR);
            int command = Integer.parseInt(st.nextToken());
            int Lcnt = cs.list.size();
            clientdata.split("\\|");
            switch(command) {
               case REQ_LOGON : { //1001|아이디 를 수신한 경우
            	   //xxx가 로그인 하였습니다.
                  String ID = st.nextToken();
                  display.append(ID + "가 로그인하였습니다.\r\n");  
                  //display.append(ID + " 로그인 하였습니다.\r\n");
                 
                  cs.hash.put(ID, this); 
                  break;
               }
               case REQ_SENDWORDS : { //1021|아이디|대화말 를 수신한 경우
            	   //모든 클라이언트에 
            	   //아이디:대화말
                  String ID = st.nextToken();
                  String message = st.nextToken();
                  display.append(ID + ":" + message + "\r\n");
                  for(int i=0; i<Lcnt; i++) {
                     WhisperThread SThread = (WhisperThread)cs.list.get(i);
                     SThread.output.write(ID + ":" + message + "\r\n");
                     SThread.output.flush();
                  }
                  break;
               }
               case REQ_WISPERSEND: {
            	   String ID = st.nextToken();
            	   String WID = st.nextToken();
            	   String message = st.nextToken();
            	   display.append(ID + " -> " + WID + " : "+message+"\r\n");
            	   WhisperThread SThread = (WhisperThread)cs.hash.get(ID);
            	   //해쉬 테이블에서 귓속말 메시지를 전송한 클라이언트의 스레드를 구함
            	   SThread.output.write(ID + " -> " + WID + " : "+message+"\r\n");
            	   //귓속말 메시지를 전송한 클라이언트에 전송함
            	   SThread.output.flush();
            	   SThread = (WhisperThread)cs.hash.get(WID);
            	   //해쉬 테이블에서 귓속말 메시지를 수신할 클라이언트의 스레드를 구함
            	   SThread.output.write(ID + " : " + message + "\r\n");
            	   //귓속말 메시지를 수신할 클라이언트에 전송함
            	   SThread.output.flush();
            	   break;
               }

            }
         }
      } catch(IOException e) {
         e.printStackTrace();
      }
      cs.list.remove(this);
      try{
         sock.close();
      }catch(IOException ea){
         ea.printStackTrace();
      }
      
   }
}