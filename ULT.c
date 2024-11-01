import java.net.*;
import java.io.*;
public class Server {
    private ServerSocket server = null;
    private Socket socket = null;
    private DataInputStream input = null;
        private Server(int port) {
            try{
                server = new ServerSocket(port);
                System.out.println("Server established ");
                System.out.println("Waiting for Client");
                socket = server.accept();
                System.out.println("Connected to client");
                input = new DataInputStream(socket.getInputStream());
                String line = "";
                while(!line.equalsIgnoreCase("Over")) {
                    line = input.readUTF();
                    System.out.println(line);
                }
                System.out.println("Closing Connection");
            }catch(Exception E) {
                System.out.println(E);
            }
            finally {
                try{
                if(server != null) {
                    server.close();
                }
                if(input != null) {
                    input.close();
                }
                if(socket != null) {
                    socket.close();
                }
            }
            catch(Exception E) {
                System.out.println(E);
            }
        }   
        
        }
        public static void main(String [] args) {
          //  Server server = new Server(5000);
        new Server(5000);
        
        }


}
