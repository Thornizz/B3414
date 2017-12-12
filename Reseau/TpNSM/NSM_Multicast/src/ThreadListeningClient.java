/**
 * Classe permettant à un client d'attendre des messages d'un serveur.
 * 
 * @author Loïc CASTELLON & Florian MUTIN 3IF4
 * 
 */

import java.net.*;

public class ThreadListeningClient extends Thread
{

	private MulticastSocket s;
	private Client c;
	
	/**
	 * 
	 * @param s la socket qui permet la connexion avec le serveur
	 * @param c le client qui attend les message du serveur
	 */	
	public ThreadListeningClient(MulticastSocket s, Client c)
	{
		this.s = s;
		this.c = c;
		this.start();
	}

	/**
	 * Méthode qui tourne à l'infini en attendant des messages.
	 * Lorsqu'un message est reçu, il est affiché chez le client.
	 */
	public void run()
	{
		try
		{
    		while (true) {
    		    byte[] buf = new byte[1000];
    		    DatagramPacket recv = new DatagramPacket(buf,buf.length);
    	    	s.receive(recv);
    	    	String recu = new String(buf);
    	    	System.out.println("RECU : "+recu);
    	    	c.affiche(recu);
    		}
    	}
		catch (Exception e) {
        	System.err.println("Error in ThreadListeningClient::run :" + e); 
        	e.printStackTrace();
    	}
	}
}