import java.io.*;
import java.net.*;

public class ThreadListeningServer extends Thread
{
	
	private Socket socket;
	private Server server;
	
	ThreadListeningServer(Socket socket, Server server)
	{
		this.socket = socket;
		this.server = server;
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
    			server.affiche(line);
    		}
    	}
		catch (Exception e) {
        	System.err.println("Error in EchoServer:" + e); 
    	}
	}
}