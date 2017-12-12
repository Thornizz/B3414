import java.io.*;
import java.net.*;

public class ThreadListeningServer extends Thread
{
	
	private Socket socket;
	private Server server;
	private IHMServer ihmServer;
	
	ThreadListeningServer(Socket socket, Server server, IHMServer ihmServer)
	{
		this.socket = socket;
		this.server = server;
		this.ihmServer = ihmServer;
	}
	
	public void run()
	{
		try
		{
    		BufferedReader socIn = null;
    		socIn = new BufferedReader(
    			new InputStreamReader(socket.getInputStream()));
    		while (true) {
    			String line = socIn.readLine();
    			ihmServer.affiche(line);
    			server.envoyer(line);
    		}
    	}
		catch (Exception e) {
			ihmServer.affiche("##### Deconnexion from:" + socket.getInetAddress());
			try
			{
				socket.close();
				server.remove(socket);
			}
			catch (Exception e1) {
				System.err.println("Error in ThreadListeningServer::run:" + e1);
				ihmServer.affiche("");
				ihmServer.affiche("~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
				ihmServer.affiche("~~~~~~~~~~ ERREUR ~~~~~~~~~~");
				ihmServer.affiche("~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
				ihmServer.affiche("");
		    }
    	}
	}
}