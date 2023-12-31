/*Program: Implementation of Go-Back-N Flow Control Protocol - GBNServer.java*/
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;
import java.net.SocketException;
public class GBNServer { 
    static ServerSocket Serversocket;
    static DataInputStream dis;
    static DataOutputStream dos;
    public static void main(String[] args) throws SocketException { 
        try { 
            int a[] = { 30, 40, 50, 60, 70, 80, 90, 100 };
            Serversocket = new ServerSocket(8011);
            System.out.println("waiting for connection");
            Socket client = Serversocket.accept();
            dis = new DataInputStream(client.getInputStream());
            dos = new DataOutputStream(client.getOutputStream());
            System.out.println("The number of packets sent is:"+ a.length);
            int y = a.length;
            dos.write(y);
            dos.flush();
            for (int i = 0; i < a.length; i++) { 
                dos.write(a[i]);
                dos.flush();
            }
            int k = dis.read();
            for(int i=k;i<a.length;i++) { 
                dos.write(a[i]);
                dos.flush();
            }
        }
        catch (IOException e) { 
            System.out.println(e);
        }
        finally { 
            try { 
                dis.close();
                dos.close();
            }
            catch (IOException e) { 
                e.printStackTrace();
            }
        }
    }
}