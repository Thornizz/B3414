/**
 * Classe permettant à un serveur d'attendre des messages d'un client.
 * 
 * @author Loïc CASTELLON & Florian MUTIN 3IF4
 * 
 */

import java.io.*;
import java.net.*;

public class ThreadListeningServer extends Thread
{
	
	private Socket socket;
	private Server server;
	private IHMServer ihmServer;
	
	/**
	 * 
	 * @param socket le client dont on attend les messages
	 * @param server le serveur qui attend les message
	 * @param ihmServer la classe qui gère l'affichage du serveur qui attend les messages
	 */
	public ThreadListeningServer(Socket socket, Server server, IHMServer ihmServer)
	{
		this.socket = socket;
		this.server = server;
		this.ihmServer = ihmServer;
	}

	
	/**
	 * Méthode qui tourne à l'infini en attendant des messages du client.
	 * Lorsqu'un message est reçu, il est affiché dans l'ihmServer, et retransmit aux autres clients du serveur.
	 */
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