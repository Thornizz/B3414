import java.io.*;
import java.net.Socket;
import java.net.UnknownHostException;

public class Client
{
	@SuppressWarnings("unused")
	private String pseudo;
	
	public Client(String ip,int port, String pseudo)
	{
		this.pseudo = pseudo;
        Socket socket = null;
        PrintStream socOut = null;
        BufferedReader stdIn = null;
        BufferedReader socIn = null;

    	System.out.println("##### Fenêtre de "+pseudo+" #####"+'\n');
    	
        try
        {
      	    socket = new Socket(ip,port);
      	    ThreadListeningClient threadListeningClient = new ThreadListeningClient(socket,this);
      	  	threadListeningClient.start();
      	    socIn = new BufferedReader(
      	    		new InputStreamReader(socket.getInputStream()));    
      	    socOut= new PrintStream(socket.getOutputStream());
      	    stdIn = new BufferedReader(new InputStreamReader(System.in));
        }
        catch (UnknownHostException e)
        {
            System.err.println("Don't know about host:" + ip);
            System.exit(1);
        }
        catch (IOException e)
        {
            System.err.println("Couldn't get I/O for "
                               + "the connection to:"+ ip);
            System.exit(1);
        }

        try {
        	socOut.println("***** "+pseudo+" est connecté *****");
	        String line;
	        while (true) {
	        	line=stdIn.readLine();
	        	if (line.equals(".")) break;
	        	socOut.println(pseudo+" : "+line);
	        }
        }
        catch (IOException e)
        {
            System.err.println("Error in Client "+ ip);
            System.exit(1);
        }
        
        try {
		    socOut.close();
		    socIn.close();
		    stdIn.close();
		    socket.close();
		    } catch (IOException e) {
		    	System.err.println("Error in Client "+ ip);
		    	System.exit(1);
		    }
    }
	
	public void affiche(String texte)
	{
    	System.out.println(texte);
	}
	
	public static void main(String[] args)
	{
		new Client("127.0.0.1",5001,"Jean");
	}
}
