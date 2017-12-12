/**
 * Classe permettant à un client d'attendre des messages d'un serveur.
 * 
 * @author Loïc CASTELLON & Florian MUTIN 3IF4
 * 
 */

import java.io.*;
import java.net.*;

public class ThreadListeningClient extends Thread
{

	private Socket socket;
	private Client client;
	
	/**
	 * 
	 * @param socket la socket qui permet la connexion avec le serveur
	 * @param client le client qui attend les message du serveur
	 */
	public ThreadListeningClient(Socket socket,Client client)
	{
		this.socket = socket;
		this.client = client;
		
	}

	/**
	 * Méthode qui tourne à l'infini en attendant des messages du serveur.
	 * Lorsqu'un message est reçu, il est affiché chez le client.
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
    			client.affiche(line);
    		}
    	}
		catch (Exception e) {
        	System.err.println("Error in ThreadListeningClient::run :" + e); 
        	e.printStackTrace();
    	}
	}
}