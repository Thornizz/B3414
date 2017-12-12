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
	
	public void affiche(String texte)
	{
		discussionClient.affiche(texte);
		System.out.println(texte);
	}
	
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
