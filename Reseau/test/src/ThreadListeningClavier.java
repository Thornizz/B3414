import java.io.*;

public class ThreadListeningClavier extends Thread
{

	private Client client;
	
	ThreadListeningClavier(Client client)
	{
		this.client = client;
		
	}
	
	public void run()
	{
		BufferedReader stdIn = null;
		String line;
		try
		{
		    stdIn = new BufferedReader(new InputStreamReader(System.in));
    		while (true) {
    			line = stdIn.readLine();
    			client.envoyer(line);
    		}
    	}
		catch (Exception e) {
        	System.err.println("Error in ThreadListeningClavier::run :" + e); 
    	}
	}
}