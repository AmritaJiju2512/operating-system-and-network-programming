/*Program: Implement Client-Server Communication using Sockets TCPClientSocket.java */
import java.io.*;
import java.net.*;
import java.util.*;
    public class TCPClientSocket {
        public static void main(String[] args) throws Exception {
        try{
        Socket socket=new Socket("127.0.0.1",8888);
        DataInputStream inStream=new DataInputStream(socket.getInputStream());
        DataOutputStream outStream=new DataOutputStream(socket.getOutputStream());
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        String clientMessage="",serverMessage="";
        System.out.println("Enter message");
        clientMessage=br.readLine();
        outStream.writeUTF(clientMessage);
        outStream.flush();
        serverMessage=inStream.readUTF();
        System.out.println("From Server: "+serverMessage);
        outStream.close();
        outStream.close();
        socket.close();
        }catch(Exception e){
            System.out.println(e);
        }
    }
}