/**
 * Classe permettant à un serveur d'attendre des connexions de clients.
 * 
 * @author Loïc CASTELLON & Florian MUTIN 3IF4
 * 
 */

import java.io.PrintStream;
import java.net.*;

public class ThreadWaitingServer  extends Thread
{

	private Server server;
	private int port;
	private IHMServer ihmServer;
	
	/**
	 * @param server le serveur qui fait appel au constructeur
	 * @param port le port correspondant au serveur
	 * @param ihmServer l'affichage graphique correspondant au serveur qui fait appel au constructeur
	 */
	public ThreadWaitingServer(Server server,int port, IHMServer ihmServer)
	{
		this.ihmServer = ihmServer;
		this.server = server;
		this.port = port;
	}
	
	/**
	 * Méthode qui tourne à l'infini en attendant des connexions de clients.
	 * Lorsqu'un client se connecte la méthode lui envoie l'historique, l'ajoute à la liste des clients du serveur et lance un thread qui attend ses messages.
	 */
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
