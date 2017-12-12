/**
 * 
 *  Cette classe gère chaque client 
 *  @author Loïc CASTELLON et Florian MUTIN 3IF4
 * 
 */

import java.io.*;
import java.net.*;

public class Client
{
	private InetAddress address; 
	private int port;
	private MulticastSocket s;
	private String pseudo;
    private DiscussionClient discussionClient;
	
    /**
     * 
	 * @param pseudo pseudo du client
	 * @param discussionClient affichage de la discussion côté client
     */
	public Client(String pseudo, DiscussionClient discussionClient)
	{
    	System.out.println("##### Fenêtre de "+pseudo+" #####"+'\n');
    	
		this.pseudo = pseudo;
		this.discussionClient = discussionClient;
		this.port = Server.PORT;
		
        try
        {	    	
    		this.address = InetAddress.getByName(Server.IP);
	    	s = new MulticastSocket(port);
	    	s.joinGroup(address);
	    	
	    	new ThreadListeningClient(s,this);
	    	
	    	String texte ="***** "+pseudo+" est connecté *****";
	    	DatagramPacket dp = new DatagramPacket(texte.getBytes(),texte.length(),address,port);
		    s.send(dp);
        }
        catch (IOException e)
        {
            System.err.println("Error in Client::Client : "+e);
            System.exit(1);
        }
    }


	/**
	 * Permet l'affichage sur la fenêtre d'un message reçu 
	 * @param texte le message à afficher
	 */
	public void affiche(String texte)
	{
		discussionClient.affiche(texte);
		System.out.println(texte);
	}

	/**
	 * Permet d'envoyer un message sur la discussion
	 * @param texte le message à envoyer
	 */
	public void envoyer(String texte)
	{    	
		if(texte.equals(Server.DECONNEXION))
		{	    	
			try
			{
		    	String decoTexte ="***** "+pseudo+" est déconnecté *****";
		    	DatagramPacket dp = new DatagramPacket(decoTexte.getBytes(),decoTexte.length(),address,port);
			    s.send(dp);
				s.leaveGroup(address);
				s.close();
			}
	        catch (IOException e)
	        {
	            System.err.println("Error in Client::Envoyer(1) : "+e);
	            System.exit(1);
	        }
		}
		else
		{
			texte = this.pseudo+" : "+texte;
	    	DatagramPacket dp = new DatagramPacket(texte.getBytes(),texte.length(),address,port);
			try
			{
		    	s.send(dp);
			}
	        catch (IOException e)
	        {
	            System.err.println("Error in Client::Envoyer(2) : "+e);
	            System.exit(1);
	        }
		}
	}
}
