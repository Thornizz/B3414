import java.io.PrintStream;
import java.net.*;

public class ThreadWaitingServer  extends Thread
{

	private Server server;
	private int port;
	private IHMServer ihmServer;
	
	ThreadWaitingServer(Server server,int port, IHMServer ihmServer)
	{
		this.ihmServer = ihmServer;
		this.server = server;
		this.port = port;
	}
	
	public void run()
	{
		ServerSocket listenSocket;
		try
		{
			listenSocket = new ServerSocket(port);
			ihmServer.affiche("##### Server ready...");
			while (true) {
				Socket socket = listenSocket.accept();
				ihmServer.affiche("##### Connexion from:" + socket.getInetAddress());
				
				PrintStream socOut = new PrintStream(socket.getOutputStream());
				socOut.print(server.getHistorique());
				
				server.add(socket);
				ThreadListeningServer threadListeningServer = new ThreadListeningServer(socket,server,ihmServer);
				threadListeningServer.start();
			}
		}
		catch (Exception e) {
			System.err.println("Error in Server::Server:" + e);
			ihmServer.affiche("");
			ihmServer.affiche("~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
			ihmServer.affiche("~~~~~~~~~~ ERREUR ~~~~~~~~~~");
			ihmServer.affiche("~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
			ihmServer.affiche("");
	    }
	}

}
