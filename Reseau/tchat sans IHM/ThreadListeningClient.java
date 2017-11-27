import java.io.*;
import java.net.*;

public class ThreadListeningClient extends Thread
{

	private Socket socket;
	private Client client;
	
	ThreadListeningClient(Socket s,Client c)
	{
		this.socket = s;
		this.client = c;
		
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
    			client.affiche(line);
    		}
    	}
		catch (Exception e) {
        	System.err.println("Error in EchoServer:" + e); 
    	}
	}
}