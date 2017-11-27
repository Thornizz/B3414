import java.io.PrintStream;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.ArrayList;

public class Server
{
	
	private ArrayList<Socket> sockets;
	private String historique;
	
	public Server(int port)
	{
		sockets = new ArrayList<Socket>();
		historique = "";
		ServerSocket listenSocket;
		try
		{
			listenSocket = new ServerSocket(port); //port
			System.out.println("Server ready..."); 
			while (true) {
				Socket socket = listenSocket.accept();
				System.out.println("Connexion from:" + socket.getInetAddress());
				
				PrintStream socOut = new PrintStream(socket.getOutputStream());
				socOut.print(historique);
				
				sockets.add(socket);
				
				ThreadListeningServer threadListeningServer = new ThreadListeningServer(socket,this);
				threadListeningServer.start();
			}
		}
		catch (Exception e) {
	            System.err.println("Error in Server:" + e);
	    }
	}

	public void affiche (String texte)
	{
		historique += texte + '\n';
		for(int i=0;i<sockets.size();i++)
		{
			try
			{
				PrintStream socOut = new PrintStream(sockets.get(i).getOutputStream());
				socOut.println(texte);
			}
			catch (Exception e)
			{
		            System.err.println("Error in Server::affiche :" + e);
		    }
		}
	}
	
	public static void main(String args[])
	{
		new Server(5001);
	}
}
