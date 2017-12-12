import java.net.*;

public class ThreadListeningClient extends Thread
{

	private MulticastSocket s;
	private Client c;
	
	public ThreadListeningClient(MulticastSocket s, Client c)
	{
		this.s = s;
		this.c = c;
		this.start();
	}
	
	public void run()
	{
	    byte[] buf = new byte[1000];
	    DatagramPacket recv = new DatagramPacket(buf,buf.length);
		try
		{
    		while (true) {
    	    	s.receive(recv);
    	    	String recu = new String(buf);
    	    	c.affiche(recu);
    		}
    	}
		catch (Exception e) {
        	System.err.println("Error in ThreadListeningClient::run :" + e); 
        	e.printStackTrace();
    	}
	}
}