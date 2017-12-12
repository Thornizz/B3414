/**
 * 
 *  Cette classe gère chaque client 
 *  @author Loïc CASTELLON et Florian MUTIN 3IF4
 * 
 */

import java.io.*;
import java.net.Socket;
import java.net.UnknownHostException;

public class Client
{
	private String pseudo;
	private Socket socket;
    private PrintStream socOut;
    private BufferedReader socIn;
    private DiscussionClient discussionClient;
    
	/**
	 * 
	 * @param ip ip à laquelle le client se connecte
	 * @param port port auquel le cient se connecte
	 * @param pseudo pseudo du client
	 * @param discussionClient affichage de la discussion côté client
	 */
	public Client(String ip,int port, String pseudo, DiscussionClient discussionClient)
	{
		this.pseudo = pseudo;
		this.discussionClient = discussionClient;
        socket = null;
        socOut = null;
        socIn = null;

    	System.out.println("##### Fenêtre de "+pseudo+" #####"+'\n');
    	
        try
        {
      	    socket = new Socket(ip,port);
      	    ThreadListeningClient threadListeningClient = new ThreadListeningClient(socket,this);
      	  	threadListeningClient.start();
      	    socIn = new BufferedReader(
      	    		new InputStreamReader(socket.getInputStream()));    
      	    socOut= new PrintStream(socket.getOutputStream());
      	    
        	socOut.println("***** "+pseudo+" est connecté *****");
        }
        catch (UnknownHostException e)
        {
            System.err.println("Error in Client::Client : Don't know about host:" + ip);
            System.exit(1);
        }
        catch (IOException e)
        {
            System.err.println("Error in Client::Client  : Couldn't get I/O for "
                               + "the connection to:"+ ip);
            System.exit(1);
        }
    }
	/**
	 * Permet l'affiche sur la discussion d'un message reçu 
	 * @param texte le message à afficher
	 */
	public void affiche(String texte)
	{
		discussionClient.affiche(texte);
		System.out.println(texte);
	}
	/**
	 * Ferme la discussion
	 */
	public void close()
	{
        try
        {
		    socOut.close();
		    socIn.close();
		    socket.close();
		}
        catch (IOException e)
        {
		   	System.err.println("Error in Client::close");
		   	System.exit(1);
		}
	}
	/**
	 * Permet d'envoyer un message sur la discussion
	 * @param texte le message à envoyer
	 */
	public void envoyer(String texte) {
		if(texte.equals(Server.DECONNEXION))
		{
			socOut.println("***** "+pseudo+" est déconnecté *****");
			this.close();
		}
		else
		{
			socOut.println(pseudo+" : "+texte);
		}
	}
}
