package src;
// Step 4
// Ŭ���̾�Ʈ ���� ä�ÿ��� Ư�� Ŭ���̾�Ʈ���� �ӼӸ� ����
// ������ �������� �ӼӸ� ����
// /w ������̵� ��ȭ��
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
      super("����");
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
               info.setText(sock.getInetAddress().getHostName() + " ������ Ŭ���̾�Ʈ�� �����");
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
	   //clientdata�� "1001|���̵�" �Ǵ�
	   //1021|����������̵�|��ȭ��
      try {   
    	  cs.list.add(this);
         while((clientdata = input.readLine()) != null) {
            StringTokenizer st = new StringTokenizer(clientdata, SEPARATOR);
            int command = Integer.parseInt(st.nextToken());
            int Lcnt = cs.list.size();
            clientdata.split("\\|");
            switch(command) {
               case REQ_LOGON : { //1001|���̵� �� ������ ���
            	   //xxx�� �α��� �Ͽ����ϴ�.
                  String ID = st.nextToken();
                  display.append(ID + "�� �α����Ͽ����ϴ�.\r\n");  
                  //display.append(ID + " �α��� �Ͽ����ϴ�.\r\n");
                 
                  cs.hash.put(ID, this); 
                  break;
               }
               case REQ_SENDWORDS : { //1021|���̵�|��ȭ�� �� ������ ���
            	   //��� Ŭ���̾�Ʈ�� 
            	   //���̵�:��ȭ��
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
            	   //�ؽ� ���̺��� �ӼӸ� �޽����� ������ Ŭ���̾�Ʈ�� �����带 ����
            	   SThread.output.write(ID + " -> " + WID + " : "+message+"\r\n");
            	   //�ӼӸ� �޽����� ������ Ŭ���̾�Ʈ�� ������
            	   SThread.output.flush();
            	   SThread = (WhisperThread)cs.hash.get(WID);
            	   //�ؽ� ���̺��� �ӼӸ� �޽����� ������ Ŭ���̾�Ʈ�� �����带 ����
            	   SThread.output.write(ID + " : " + message + "\r\n");
            	   //�ӼӸ� �޽����� ������ Ŭ���̾�Ʈ�� ������
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